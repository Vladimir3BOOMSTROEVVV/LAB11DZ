typedef struct {
    int num;             
    char punkt_otb[30];  
    int h_otb, m_otb;    
    char punkt_prib[30]; 
    int h_prib, m_prib;  
} Train;
Train input_train();
void print_train(Train t);
int check(Train t);
int writefile(char* fname, Train t1, Train t2, Train t3);