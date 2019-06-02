
#include <stdio.h>
#include <math.h>

/*
	Program to compute a sin cos table
*/

#define PI 3.14156

typedef struct element {
	int type;
	int number1;
	long number2;
	char *label;
} element;

#define TYPE_BYTE 1
#define TYPE_WORD 2
#define TYPE_LONG 3
#define TYPE_LABEL_WORD 4
#define TYPE_LABEL_LONG 5

void make_outstring(FILE *f,char *s)
{
	if(f==NULL)
		printf("%s",s);
	else
		fprintf(f,"%s",s);
}

int current_tab,max_tab;

void make_table(FILE *f,element *n)
{
	char string[128];

	if(current_tab==0)
	{
		make_outstring(f,"\n\tdc.");

		switch(n->type) {
			case TYPE_BYTE: make_outstring(f,"b"); break;
			case TYPE_LABEL_WORD:
			case TYPE_WORD: make_outstring(f,"w"); break;
			case TYPE_LABEL_LONG:
			case TYPE_LONG: make_outstring(f,"l"); break;
			}

		make_outstring(f," ");
	}
	else
		make_outstring(f,",");

	switch(n->type) {
		case TYPE_BYTE:
		case TYPE_WORD:
		{
			sprintf(string,"%d",(int)n->number1);
			break;
		}
		case TYPE_LONG:
		{
			sprintf(string,"%ld",(long)n->number2);
			break;
		} 
		case TYPE_LABEL_WORD:
		case TYPE_LABEL_LONG:
		{
			sprintf(string,"%s",n->label);
			break;
		}

		default:
		{
			printf("Illegal element type\n"); exit(1); break;
		}
	}

	make_outstring(f,string);

	if(++current_tab >= max_tab) current_tab=0;

}

void init_table(FILE *f,char *tablename,int tabsize)
{
	max_tab=tabsize;
	current_tab=0;

	make_outstring(f,tablename);
	make_outstring(f,":");
}

void close_table(FILE *f)
{
	make_outstring(f,"\n");
}

FILE *init_file(char *filename)
{
	if(strlen(filename)!=0)
	{
		return(fopen(filename,"w"));
	}
	else
		return(NULL);
}

void close_file(FILE *f)
{
	if (f!=NULL)
		fclose(f);
}

generate(int size,int extend,char *name)
{
	FILE *f;
	int i;
	double step,angle;
	element e;

	if(NULL==(f=fopen(name,"w")))
		return 1;

	step = (2.0*PI)/(double)size;

	init_table(f,"SIN",16);

	e.type	= TYPE_WORD;

	angle = 0.0;

	for(i=0;i!=size;i++)
	{
		e.number1=(int)((double)extend*sin(angle));
		angle+=step;
		make_table(f,&e);
	}

	close_table(f);
	
	init_table(f,"COS",16);

	angle = 0.0;

	for(i=0;i!=size;i++)
	{
		e.number1=(int)((double)extend*cos(angle));
		angle+=step;
		make_table(f,&e);
	}

	close_table(f);
			
	fclose(f);

	return 0;
}

main(int argc,char **argv)
{
	int i;
	int size,ext;
	char outfile[80];

	if(argc==1)
	{
		printf("Usage:\n");
		printf("\tSINCOS\t<outfile>\n\t\t");
		printf("-s<tablesize> -e<extend_multiply>\n");
		exit(1);
	}

	size=-1;outfile[0]=0;ext=-1;

	for(i=1;i!=argc;i++)
	{
		if(argv[i][0]=='-')
		{
			switch(tolower(argv[i][1])) {
				case 's':
						sscanf(&argv[i][2],"%d",&size);
						break;
				case 'e':
						sscanf(&argv[i][2],"%d",&ext);
						break;
				default: printf("Unknown switch '%c'\n",argv[i][1]); exit(1);
							}
		}
		else
		{
			if(strlen(outfile)==0)
				strcpy(outfile,argv[i]);
			else
			{
				printf("Outfile specified twice\n");
				exit(1);
			}
		}
	}

	if(size<1) { printf("Unspecified table size\n"); exit(1); }
	if(ext<1) { printf("Unspecified extend multiply\n"); exit(1); }
	if(strlen(outfile)==0) { printf("No outfile specified\n"); exit(1); }

	if(generate(size,ext,outfile))
		return 1;
	else
		return 0;
}
