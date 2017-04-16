#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int main()
{
	FILE *f1;
	char line[100], chain_id1[2],chain_id2[2], atom_type1[2], atom_type2[2], DA[3];
	f1 = fopen("1ASY.hb2","r");
	int inter[]={0,0,0,0,0},intra_rna[]={0,0,0,0},intra_pro[4]={0,0,0,0};
	int i ;
	while(fgets(line,100,f1))
	{	
		//printf("%c\n", line[15] );
		for (i = 0; i < 1; i++)
		{
			chain_id1[i]=line[i];
			chain_id2[i]=line[i+14];
		}
		chain_id2[1]='\0';
		chain_id1[1]='\0';

		for (i = 0; i < 2; i++)
		{
			DA[i]= line[i+33];
		}
		DA[2]='\0';

		for (i = 0; i < 1; i++)
		{
			atom_type1[i] = line[i+10];
			atom_type2[i] = line[24+i];
		}
		atom_type2[1]='\0';
		atom_type1[1]='\0';

		if((strcmp(chain_id1,"R")==0 || strcmp(chain_id1,"S")==0) && (strcmp(chain_id2,"R")==0 || strcmp(chain_id2,"S")==0) )
		{
			/*intra RNA*/
			intra_rna[0]++;
			if(strcmp(atom_type1,atom_type2)==0)
			{
				if( strcmp(atom_type1,"N")==0) intra_rna[1]++;
				else intra_rna[2]++;
			}
			else intra_rna[3]++;
		}

		else if((strcmp(chain_id1,"A")==0 || strcmp(chain_id1,"B")==0) && (strcmp(chain_id2,"A")==0 || strcmp(chain_id2,"B")==0) )
		{
			/*intra protein*/
			intra_pro[0]++;
			if (strcmp(DA,"MM")==0) intra_pro[1]++;
			else if(strcmp(DA,"SS")==0) intra_pro[2]++;
			else intra_pro[3]++;
		}
		else if (strcmp(chain_id1,"A")==0 || strcmp(chain_id1,"B")==0 || strcmp(chain_id1,"R")==0 || strcmp(chain_id1,"S")==0)
		{
			/*inter*/
			inter[0]++;
			if(strcmp(DA,"MH")==0)
			{
				if ( strcmp(atom_type2,"O")==0)
				{
					inter[1]++;
				}
				else inter[2]++;
			}

			else if (strcmp(DA,"HM")==0 )
			{
				if ( strcmp(atom_type1,"O")==0)
				{
					inter[1]++;
				}
				else inter[2]++;
			} 
			
			else if (strcmp(DA,"SH")==0 )
			{
				if ( strcmp(atom_type2,"O")==0)
				{
					inter[3]++;
				}
				else inter[4]++;
			}

			else if (strcmp(DA,"HS")==0 )
			{
				if ( strcmp(atom_type1,"O")==0)
				{
					inter[3]++;
				}
				else inter[4]++;
			} 		
		}

	}
	printf("\nTotal number of H-bonds = %d\n", intra_rna[0]+intra_pro[0]+inter[0]);

	printf("Total number of intra RNA H-bonds = %d\n", intra_rna[0]);
	printf("  >base-base H-bonds = %d\n",intra_rna[1]);
	printf("  >backbone-bacbone H-bonds = %d\n",intra_rna[2]);
	printf("  >backbone-base H-bonds = %d\n",intra_rna[3]);

	printf("Total number of intra protein H-bonds = %d\n", intra_pro[0]);
	printf("  >main-main chain H-bonds = %d\n",intra_pro[1]);
	printf("  >side-side chain H-bonds = %d\n",intra_pro[2]);
	printf("  >main-side chain H-bonds = %d\n",intra_pro[3]);

	printf("\nTotal number of intermolecular H-bonds = %d\n", inter[0]);

	printf("Specific interaction H-bonds = %d\n",inter[4]);
	printf("  >side chain - bases H-bonds = %d\n", inter[4]);

	printf("Non-Specific interaction H-bonds = %d\n",inter[1]+inter[2]+inter[3]);
	printf("  >main chain - backbone H-bonds = %d\n", inter[1]);
	printf("  >main chain - bases H-bonds = %d\n", inter[2]);
	printf("  >side chain - backbone H-bonds = %d\n\n", inter[3]);

}
