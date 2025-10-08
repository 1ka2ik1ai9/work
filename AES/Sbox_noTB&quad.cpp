#include<iostream>
#include <iomanip>
#include<ctime> 

using namespace std;

int Nk=4,Nr=10,Nb=4;
int aff_list_count=0;
int aff_list[128];
int TB_xor[16]={0};
int sbox_GPT[256]={0};
int sbox_TB[256]={0};
int sbox_noTB[256]={0};
int sbox_quad[256]={0};
unsigned int w[44];
int key[16]={0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};
unsigned int Rcon[10];
int TableA2[8],TableA4[8];


int GFM(int a,int b)//有限體乘法 
{
	int c=0x0;
	for(int i=7;i>0;i--)
	{
		c=c^(((a>>i)&0x01)*b);    //乘法 
		c=((c<<1)&0xff)^(((c>>7)&0x01)*0x1b);
	}
	c=c^(a&0x01)*b;
	return c;
}

int A2(int a)
{
	int a2t=0;
    for(int i=0;i<8;i++)
		a2t=a2t^(((a>>i)&0x01)*TableA2[i]);
    return a2t;
}

int A4(int a)
{
	int a4t=0;
    for(int i=0;i<8;i++)
		a4t=a4t^(((a>>i)&0x01)*TableA4[i]);
    return a4t;
}

int inverseGF(int a)
{
	if(a==0)
	{
		return 0;
	}
	else
	{
		int c=a;
		for(int i=0;i<253;i++)
			c=GFM(c,a);
		return c;
	}
}

int new_inverseGF(int a)
{
	int a1=A2(a),a2=A2(a1),a3=A2(a2);
	//a1=a^2,a2=a^(2*2)=a^4,a3=a^(4*2)=a^8
	int M=GFM(GFM(a1,a2),a3),M2=A2(M),M4=A4(A2(M2));
	//M=a1*a2*a3=a^(2+4+8)=a^14,M2=a^(2*14)=a^28,M4=a^(28*2*4)=a^224
	return GFM(GFM(M2,M4),a1);
	//=a^(2+224+28)=a^254
}

int rev(int a)//反轉 
{
	int c=0;
	for(int i=0;i<8;i++)
		c=(c<<1)|((a>>i)&0x01);
	return c;
}

void build_TB()//建表(Xor,A0,A)
{
	int a=1,c=1,d=1,x2=0x04,x4=0x10;
	for(int i=0;i<Nr;i++)
	{
		Rcon[i]=a<<32;
		a=(a<<1)&0xff|((a>>7)&1)*27;
		//cout<<"Rcon["<<i<<"]="<<Rcon[i]<<endl;
	}
	for(int i=1;i<256;i++)
	{
		bool f=0;
		for(int j=0;j<8;j++)
			f=f^((i>>j)&0x01);
		if(f)
		{
			aff_list[aff_list_count]=i;
			aff_list_count++;
		}
	}	
	for(int i=0;i<16;i++)
		for(int j=0;j<4;j++)
			TB_xor[i]=TB_xor[i]^((i>>j)&0x01);
	for(int i=0;i<8;i++)
	{
		TableA2[i]=c;
		TableA4[i]=d;
		c=GFM(c,x2);
		d=GFM(d,x4);
	}
}

void affineTransform_noTB(int a)
{
	int af[8],y=0,b,temp,bity;
	af[0]=a;
	for(int i=0;i<7;i++)
		af[i+1]=(af[i]>>1)|((af[i]&0x01)<<7);
	for(int k=0;k<256;k++)
	{
		y=0;
		b=rev(new_inverseGF(k));
		for(int i=0;i<8;i++)
		{
			temp=b&af[i];
			bity=0;
			for(int j=0;j<8;j++)
			bity=bity^((temp>>j)&0x01);
			y=y|(bity<<i);
		}	
		sbox_noTB[k]=y^0x63;
	}
}

void affineTransform_TB(int a)
{
	int af[8],y,b,b1=0,temp,bity=0;
	af[0]=a;
	for(int i=0;i<7;i++)
		af[i+1]=(af[i]>>1)|((af[i]&0x01)<<7);
	for(int j=0;j<256;j++)
	{
		y=0;
		b=new_inverseGF(j);
		for(int i=0;i<8;i++)
			b1=(b1<<1)|((b>>i)&0x01);
		for(int i=0;i<8;i++)
		{
			temp=b1&af[i];
			bity=TB_xor[temp>>4]^TB_xor[temp&0xf];
			y=y|(bity<<i);
		}
		sbox_TB[j]=y^0x63;
	}
}

void affineTransform_quad(int a)
{
	int A0[4],A1[4],A[4],afft[4],B0,B1,b,F,G,FT[16],GH[16];
	afft[0]=a;
    afft[1]=(afft[0]>>1)|((afft[0]&0x01)<<7);
    afft[2]=(afft[1]>>1)|((afft[1]&0x01)<<7);
    afft[3]=(afft[2]>>1)|((afft[2]&0x01)<<7);
    
	A0[0]=afft[0]>>4;A0[1]=afft[1]>>4;
    A0[2]=afft[2]>>4;A0[3]=afft[3]>>4;
	
  	A[0]=(afft[0]&0xf)^(afft[0]>>4);A[1]=(afft[1]&0xf)^(afft[1]>>4);
    A[2]=(afft[2]&0xf)^(afft[2]>>4);A[3]=(afft[3]&0xf)^(afft[3]>>4);
 
	//making matrix F,G,and H
 	for(int i=0;i<16;i++)
 	{
 		F=0,G=0;
 		for(int j=0;j<4;j++)
 		{
 			F=F|(TB_xor[A0[j]&i]<<j);
 			G=G|(TB_xor[A[j]&i]<<j);
		}
		FT[i]=F;
        GH[i]=G;
	}
	for(int i=0;i<256;i++)
	{
		b=new_inverseGF(i);// reverse delete
 		B0=0; B1=0;
        for(int j=0;j<4;j++) // reverse data
        {
           B0=(B0<<1)|((b>>j)&0x01);
           B1=(B1<<1)|((b>>(j+4))&0x01);       
        }     
        F=FT[B0^B1];
        sbox_quad[i]=(((F^GH[B0])<<4)|(F^GH[B1]))^0X63;    
    }                                
}

void affineTransform_GPT(int a)//GPT
{
	int af[8],y,sum,b;
	af[0]=a;
	for(int i=0;i<7;i++)
		af[i+1]=(af[i]>>1)|((af[i]&0x01)<<7);
	for(int k=0;k<256;k++)
	{
		y=0; 
		b=new_inverseGF(k);
		for(int i=0;i<8;i++)
		{
			sum=0;
			for(int j=0;j<8;j++)
			{
				if(af[7-j]&0x01)
				{
					sum=sum^((b>>((i+j)%8))&0x1);
				}
			}
			sum=sum^((0x63>>i)&1);
			y|=(sum<<i);
		}
		sbox_GPT[k]=y;
	}
  
}

void Sbox_out()
{
	cout<<"Sbox_GPT:"<<endl;
	for(int i=0;i<256;i++)
	{
		if(i%16==15)
		{
			cout<<hex<<sbox_GPT[i]<<" "<<endl;
		}
		else
		{
			cout<<hex<<sbox_GPT[i]<<" ";
		}
	}
	cout<<"Sbox_noTB:"<<endl;
	for(int i=0;i<256;i++)
	{
		if(i%16==15)
		{
			cout<<hex<<sbox_noTB[i]<<" "<<endl;
		}
		else
		{
			cout<<hex<<sbox_noTB[i]<<" ";
		}
	}
	cout<<"Sbox_TB:"<<endl;
	for(int i=0;i<256;i++)
	{
		if(i%16==15)
		{
			cout<<hex<<sbox_TB[i]<<" "<<endl;
		}
		else
		{
			cout<<hex<<sbox_TB[i]<<" ";
		}
	}
	cout<<"Sbox_quad:"<<endl;
	for(int i=0;i<256;i++)
	{
		if(i%16==15)
		{
			cout<<hex<<sbox_quad[i]<<" "<<endl;
		}
		else
		{
			cout<<hex<<sbox_quad[i]<<" ";
		}
	}
}

void Table_out()
{
	cout<<"TableA2:"<<endl;
	for(int i=0;i<8;i++)
		cout<<dec<<"TableA2["<<i<<"]:"<<hex<<"0x"<<TableA2[i]<<" "<<endl;
	cout<<"TableA4:"<<endl;
	for(int i=0;i<8;i++)
		cout<<dec<<"TableA4["<<i<<"]:"<<hex<<"0x"<<TableA4[i]<<" "<<endl;;
	cout<<endl;
} 

unsigned int RotWord(unsigned int s)
{
	s=(s<<8)&0xffffffff|(s>>24);
	return s;
}

unsigned int SubWord_quard(unsigned int s)
{
	unsigned int r=sbox_quad[(s>>24)&0xff]<<24|sbox_quad[(s>>16)&0xff]<<16|sbox_quad[(s>>8)&0xff]<<8|sbox_quad[s&0xff];
	return r;
}



int main()
{
	build_TB();
	
	/*
	double GPT_start = clock();
	for(int k=1;k<=1000;k++)                      
		affineTransform_GPT(0x8f);
	double GPT_end = clock();
	double GPT_time=((GPT_end-GPT_start)/CLOCKS_PER_SEC);
	cout<<"GPT  time:"<<GPT_time<<endl;
	*/
	Table_out();
	double noTB_start = clock();
	for(int k=1;k<=1000;k++)                         
		affineTransform_noTB(0x8f);
	double noTB_end = clock();
	double noTB_time=((noTB_end-noTB_start)/CLOCKS_PER_SEC);
	cout<<"noTB  time:"<<noTB_time<<endl;
	
	double TB_start = clock();
 	for(int k=1;k<=1000;k++)
		affineTransform_TB(0x8f);
	double TB_end = clock();
	double TB_time=((TB_end-TB_start)/CLOCKS_PER_SEC);
	cout<<"TB  time:"<<TB_time<<endl;
	
 	double quad_start = clock();
 	for(int k=1;k<=1000;k++)
	 	affineTransform_quad(0x8f);
	double quad_end = clock();
	double quad_time=((quad_end-quad_start)/CLOCKS_PER_SEC);
	cout<<"quad  time:"<<quad_time<<endl;
	//Sbox_out();
	//cout<<endl<<"quad/GPT:"<<((GPT_time-quad_time)/GPT_time)*100.00<<"%";
	cout<<endl<<"quad/noTB:"<<((noTB_time-quad_time)/noTB_time)*100.00<<"%";
	cout<<endl<<"quad/TB:"<<((TB_time-quad_time)/TB_time)*100.00<<"%";
} 
