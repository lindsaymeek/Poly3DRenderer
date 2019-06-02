
#include <stdio.h>
#include <math.h>

/*
	Program to compute the formula (b+1)/sqrt(2*(b+1))
	where b=[-1,1] in *16384 fixed point and results are fixed the same
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

generate(char *name)
{
	FILE *f;
	int i;
	double b,vdoth;
	element e;

	if(NULL==(f=init_file(name)))
		return 1;

	init_table(f,"VDOTH",8);

	e.type	= TYPE_WORD;

	for(i=-16384;i<=16384;i++)
	{
		b=((double)(i+16384))/16384.0;

		vdoth = 16384.0*(b/pow(2.0*b,0.5));

		e.number1 = (int)vdoth;

		make_table(f,&e);
	}

	close_table(f);

	close_file(f);

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
		printf("\tSQRT\t<outfile>\n");
		exit(1);
	}

	outfile[0]=0;

	for(i=1;i!=argc;i++)
	{
		if(argv[i][0]=='-')
		{
			switch(tolower(argv[i][1])) {
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

	if(strlen(outfile)==0) { printf("No outfile specified\n"); exit(1); }

	if(generate(outfile))
		return 1;
	else
		return 0;
}
