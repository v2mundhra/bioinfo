#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int main()
{

FILE *f1, *f2, *f3, *final;
char  line1[100],line2[100],line3[100], word[5], res_no[5], x_no[9], y_no[9], z_no[9], asa_no[9], rad_no[7], sl_no[7];

struct complex{
char atom_nm[10000][4], res_nm[10000][4], chain_id[10000][2]; 
int store_atm_no[10000], store_res_no[10000];
float x[10000], y[10000], z[10000], asa[10000], rad[10000];
float surface_area ;
}A,B,AB;

f1 = fopen("1ASYa.asa","r");
f2 = fopen("1ASYb.asa","r");
f3 = fopen("1ASY.asa","r");
final = fopen("interface.pdb","w");
A.surface_area =0.0;
B.surface_area =0.0;
AB.surface_area =0.0;
int i, c1=0,c2=0,c3=0;
int l1=0,l2=0;
float c=0.0;
while(fgets(line3,100,f3)!=NULL)
{
	//chain_id
	AB.chain_id[c3][0] = line3[21];
	AB.chain_id[c3][1] = '\0';
	

	//serial
	for(i=0;i<6;i++)
	{
		sl_no[i] = line3[i+5];	
	}
	sl_no[6] = '\0'; 
	AB.store_atm_no[c3] = atoi(sl_no);	

	//asa
	for(i=0;i<8;i++)
	{
		asa_no[i] = line3[i+54];	
	}
	asa_no[8] = '\0'; 
	AB.asa[c3] = atof(asa_no);
	AB.surface_area = AB.surface_area + AB.asa[c3];
	c=c+AB.asa[c3];
	if(strcmp(AB.chain_id[c3],"A")==0) 
	{ 

		while(fgets(line1,100,f1)!=NULL)
		{
				
		//serial
		for(i=0;i<6;i++)
		{
			sl_no[i] = line1[i+5];	
		}
		sl_no[6] = '\0'; 
		A.store_atm_no[l1] = atoi(sl_no);	
		
		if(AB.store_atm_no[c3]==A.store_atm_no[l1])
		{			

			//asa
			for(i=0;i<8;i++)
			{
				asa_no[i] = line1[i+54];	
			}
			asa_no[8] = '\0'; 
			A.asa[c1] = atof(asa_no);
			A.surface_area = A.surface_area + A.asa[c1];

			if (A.asa[c1] <=AB.asa[c3]) { 
			break;
			} 		
			
			// atom name
			for(i=0;i<3;i++)
			{
				A.atom_nm[c1][i] = line1[i+13];
			}
			A.atom_nm[c1][3] = '\0';
					//serial
			for(i=0;i<6;i++)
			{
				sl_no[i] = line1[i+5];	
			}
			sl_no[6] = '\0'; 
			A.store_atm_no[c1] = atoi(sl_no);	


			// residual number
			for(i=0;i<3;i++)
			{
				A.res_nm[c1][i] = line1[i+17];
			}
			A.res_nm[c1][3] = '\0';
			

			// chain id
			for(i=0;i<1;i++)
			{
				A.chain_id[c1][i] = line1[i+21];
			}
			A.chain_id[c1][1] = '\0';
			
			
			//res_nm
			for(i=0;i<4;i++)
			{
				res_no[i] = line1[i+22];	
			}
			res_no[4] = '\0'; 
			A.store_res_no[c1] = atoi(res_no);
			

			//x 
			for(i=0;i<8;i++)
			{
				x_no[i] = line1[i+30];	
			}
			x_no[8] = '\0'; 
			A.x[c1] = atof(x_no);
			

			//y
			for(i=0;i<8;i++)
			{
				y_no[i] = line1[i+38];	
			}
			y_no[8] = '\0'; 
			A.y[c1] = atof(y_no);
			

			//z
			for(i=0;i<8;i++)
			{
				z_no[i] = line1[i+46];	
			}
			z_no[8] = '\0'; 
			A.z[c1] = atof(z_no);
			
								
			//radius
			for(i=0;i<6;i++)
			{
				rad_no[i] = line1[i+62];	
			}
			rad_no[8] = '\0'; 
			A.rad[c1] = atof(rad_no);
			c1++;
			break;
		}
		l1++;
		break; 
		
		}
	
		
	}

	else if(strcmp(AB.chain_id[c3],"R")==0)
	{
		while(fgets(line2,100,f2)!=NULL)
		{

		//serial
		for(i=0;i<6;i++)
		{
			sl_no[i] = line2[i+5];	
		}
		sl_no[6] = '\0'; 
		B.store_atm_no[l2] = atoi(sl_no);

		if(AB.store_atm_no[c3]==B.store_atm_no[l2])
		{	
	
			//asa
			for(i=0;i<8;i++)
			{
				asa_no[i] = line2[i+54];	
			}
			asa_no[8] = '\0'; 
			B.asa[c2] = atof(asa_no);
			B.surface_area = B.surface_area + B.asa[c2];
			
			if (B.asa[c2] <=AB.asa[c3]) { 
			break;
			} 
					
			
			// atom name
			for(i=0;i<3;i++)
			{
				B.atom_nm[c2][i] = line2[i+13];
			}
			B.atom_nm[c2][3] = '\0';

			//serial
			for(i=0;i<6;i++)
			{
				sl_no[i] = line2[i+5];	
			}
			sl_no[6] = '\0'; 
			B.store_atm_no[c2] = atoi(sl_no);
			
			// residual number
			for(i=0;i<3;i++)
			{
				B.res_nm[c2][i] = line2[i+17];
			}
			B.res_nm[c2][3] = '\0';
			

			// chain id
			for(i=0;i<1;i++)
			{
				B.chain_id[c2][i] = line2[i+21];
			}
			B.chain_id[c2][1] = '\0';
			
			
			//res_nm
			for(i=0;i<4;i++)
			{
				res_no[i] = line2[i+22];	
			}
			res_no[4] = '\0'; 
			B.store_res_no[c2] = atoi(res_no);
			

			//x 
			for(i=0;i<8;i++)
			{
				x_no[i] = line2[i+30];	
			}
			x_no[8] = '\0'; 
			B.x[c2] = atof(x_no);
			

			//y
			for(i=0;i<8;i++)
			{
				y_no[i] = line2[i+38];	
			}
			y_no[8] = '\0'; 
			B.y[c2] = atof(y_no);
			

			//z
			for(i=0;i<8;i++)
			{
				z_no[i] = line2[i+46];	
			}
			z_no[8] = '\0'; 
			B.z[c2] = atof(z_no);
			
			
			
			//radius
			for(i=0;i<6;i++)
			{
				rad_no[i] = line2[i+62];	
			}
			rad_no[8] = '\0'; 
			B.rad[c2] = atof(rad_no);
			c2++;
			break;
			
		
		}
		l2++;
		break;
		}
	

	}	
	c3++;
}

float interface_area = A.surface_area + B.surface_area - AB.surface_area;
printf("Surface Area of A = %f sq Angstrom\n",A.surface_area );
printf("\nSurface Area of B = %f sq Angstrom\n",B.surface_area );
printf("\nSurface Area of AB = %f sq Angstrom\n",AB.surface_area);
printf("\nInterface Area = %f sq Angstrom\n",interface_area );

printf("\nNumber of interface atoms of A = %d\n",c1 );
printf("\nNumber of interface atoms of B = %d\n",c2 );
printf("\nNumber of interface atoms of C = %d\n",c3 );
for(i=0;i<c1;i++)
		{
			fprintf(final,"ATOM  %5d %s %s %s%4d    %8.3f%8.3f%8.3f%8.3f%6.3f\n",A.store_atm_no[i],A.atom_nm[i],A.res_nm[i],A.chain_id[i],A.store_res_no[i],A.x[i],A.y[i],A.z[i],A.asa[i],A.rad[i]);
		}
for(i=0;i<c2;i++)
		{
			fprintf(final,"ATOM  %5d %s %s %s%4d    %8.3f%8.3f%8.3f%8.3f%6.3f\n",B.store_atm_no[i],B.atom_nm[i],B.res_nm[i],B.chain_id[i],B.store_res_no[i],B.x[i],B.y[i],B.z[i],B.asa[i],B.rad[i]);
		}

fclose(final);
fclose(f3);
fclose(f2);
fclose(f1);

}


