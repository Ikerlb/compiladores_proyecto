/*type table register*/
typedef struct{
    char type[20];
    int base_type;
    int size;
    int elem_num;
} typereg;

/*symbol table register*/
typedef struct{
    char id[20];
    typereg* type;
    int dir;
} symreg;

/*TODO: Maintain a symtable stack*/
/*TODO: Maintain a typetable stack*/

/*vector that will contain symregs*/
vector symtable;
/*vector that contains type table*/
vector typetable;

/*push a typereg struct to the typetable*/
void typetable_push(typereg* tr){
	typereg* ptr=(typereg*)malloc(sizeof(typereg));
	*ptr=(*tr);
	vector_add(&typetable,ptr);
}

int typetable_exists(char* type){
	int i;
	for (i = 0; i < vector_total(&typetable); i++){
		char* cs=((typereg*)vector_get(&typetable,i))->type;
		if(strcmp(type,cs)==0)
			return i;
	}
	return -1;
}

typereg* typetable_get(int idx){
	return (typereg*)vector_get(&typetable,idx);
}

/*initially only int float double and char values*/
void typetable_init(){
	vector_init(&typetable);
	typereg int_type={"int",-1,4,-1};
	typetable_push(&int_type);
	typereg float_type={"float",-1,4,-1};
	typetable_push(&float_type);
	typereg double_type={"double",-1,8,-1};
	typetable_push(&double_type);
	typereg char_type={"char",-1,1,-1};
	typetable_push(&char_type);
}

/*free memory allocated by typeregs and vector*/
void typetable_free(){
	int i;
	for (i = 0; i < vector_total(&typetable); i++)
        free((typereg*)vector_get(&typetable,i));
    vector_free(&typetable);
}

/*push a symreg into the symbol table*/
void symtable_push(symreg* sr){
	symreg* psr=(symreg*)malloc(sizeof(typereg));
	*psr=(*sr);
	vector_add(&symtable,psr);
}

/*create a new symreg. it depends on symtable last entry*/
symreg symreg_new(char* id,typereg* tr){
	int ts,nd,vt;
	vt=vector_total(&symtable)-1;
	if(vt==-1)
		nd=0;
	else{
		symreg* le=(symreg*)vector_get(&symtable,vt);
		ts=tr->size;
		nd=(le->dir)+ts;
	}

	symreg nsr={"",tr,nd};
	strcpy(nsr.id,id);
	return nsr;
}

/*linear search, improve!*/
/*reports index of id if it exists on symtable*/
int symtable_exists(char* id){
	int i;
	for (i = 0; i < vector_total(&symtable); i++){
		char* cs=((symreg*)vector_get(&symtable,i))->id;
		if(strcmp(id,cs)==0)
			return i;
	}
	return -1;
}

symreg* symtable_get(int idx){
	return (symreg*)vector_get(&symtable,idx);
}

/*free allocated symregs and vector*/
void symtable_free(){
	int i;
	for (i = 0; i < vector_total(&symtable); i++)
        free((symreg*)vector_get(&symtable,i));
    vector_free(&symtable);
}

int main(int argc, char** argv){
	FILE* f;
	FILE* o;
	if(argc>1){
		if((f=fopen(argv[1],"r"))==0)
			fprintf(stderr,"Error abriendo archivo\n");
	}
	else{
		fprintf(stderr,"Error el archivo se debe de pasar como un argumento.\n");
		return 0;
	}

	yyin=f;

	vector_init(&symtable);
	typetable_init();

	// symreg sr1=symreg_new("abcdefghijk",(typereg*)vector_get(&typetable,0));
	// symtable_push(&sr1);
	// printf("%s\n",sr1.id);
	// printf("%s\n",sr1.type->type);

	yyparse();

	//free typetable first, as symtable contains reference to typetable
	typetable_free();
	symtable_free();


	if(errcount>0)
		fprintf(stderr,"Hubo un total de %d errores\n",errcount);
	else
		printf("Analisis lexico concluido exitosamente\n"); 

	fclose(yyin);
}