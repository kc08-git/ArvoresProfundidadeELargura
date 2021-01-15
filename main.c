 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <math.h>

 /* estrutura autorreferenciada */
 struct treeNode {
 struct treeNode *esqPtr; /* ponteiro para sub�rvore esquerda */
 int elem; /* valor do n� */
 struct treeNode *dirPtr; /* ponteiro para sub�rvore direita */
 }; /* fim da estrutura treeNode */

 typedef struct treeNode TreeNode; /* sin�nimo para struct treeNode */
 typedef TreeNode *TreeNodePtr; /* sin�nimo para TreeNode* */

/* prot�tipos */
 void inserir( TreeNodePtr *treePtr, int value );
 void emOrdem( TreeNodePtr treePtr );
 void preOrdem( TreeNodePtr treePtr );
 void posOrdem( TreeNodePtr treePtr );
 int profundidade( TreeNodePtr treePtr );
 int largura( TreeNodePtr treePtr );

 int main(){

     int i; /* contador para loop de 1 a 10 */
     int item; /* vari�vel para manter valores aleat�rios */
     TreeNodePtr rootPtr = NULL; /* �rvore inicialmente vazia */

     srand( time( NULL ) );
     printf( "Os numeros sendo colocados na arvore sao:\n" );

     /* insere valores aleat�rios entre 0 e 14 na �rvore */
     for ( i = 1; i <= 10; i++ ) {
         item = rand() % 15;
         printf( "%3d", item );
         inserir( &rootPtr, item );
    } /* fim la�o for */

    /* atravessa a �rvore preOrdem */
     printf( "\n\nA travessia na pre-ordem ee:\n" );
     preOrdem( rootPtr );

     /* atravessa a �rvore emOrdem */
     printf( "\n\nA travessia na ordem ee:\n" );
     emOrdem( rootPtr );

     /* atravessa a �rvore posOrdem */
     printf( "\n\nA travessia na p�s-ordem ee:\n" );
     posOrdem( rootPtr );

     /* profundidade da �rvore*/

     printf( "\n\n A profundidade ee: %i \n", profundidade( rootPtr ));

     printf( "\n\n A profundidade ee: %i \n", largura( rootPtr ));

     return 0; /* indica conclus�o bem-sucedida */

 }/* Fim do main*/

 /* insere n� na �rvore */
 void inserir( TreeNodePtr *treePtr, int value )
 {
     /* se �rvore estiver vazia */
     if ( *treePtr == NULL ) {
         *treePtr = malloc( sizeof( TreeNode ) );

         /* se a mem�ria foi alocada, ent�o atribui dados */
        if ( *treePtr != NULL ) {
             ( *treePtr )->elem = value;
             ( *treePtr )->esqPtr = NULL;
             ( *treePtr )->dirPtr = NULL;
        } /* fim do if */
     else {
         printf( "%d n�o inserido. N�o h� mem�ria dispon�vel.\n", value );
         } /* fim do else */
     } /* fim do if */
     else { /* �rvore n�o est� vazia */
        /* dado a inserir � menor que dado no n� atual */
         if ( value < ( *treePtr )->elem ) {
            inserir( &( ( *treePtr )->esqPtr ), value );
         } /* fim do if */

         /* dado a inserir � maior que dado no n� atual */
         else if ( value > ( *treePtr )->elem ) {
            inserir( &( ( *treePtr )->dirPtr ), value );
         } /* fim do else if */
         else { /* valor de dado duplicado � ignorado */
            printf( "dup" );
         } /* fim do else */
    } /* fim do else */
 }

 /* inicia travessia da �rvore na ordem */
 void emOrdem( TreeNodePtr treePtr )
 {
     /* se �rvore n�o est� vazia, ent�o atravessa */
     if ( treePtr != NULL ) {
     emOrdem( treePtr->esqPtr );
     printf( "%3d", treePtr->elem );
     emOrdem( treePtr->dirPtr );
     } /* fim do if */
} /* fim da fun��o emOrdem */

 /* inicia travessia da �rvore na pr�-ordem */
 void preOrdem( TreeNodePtr treePtr )
 {
 /* se a �rvore n�o est� vazia, ent�o atravessa */
 if ( treePtr != NULL ) {
     printf( "%3d", treePtr->elem );
     preOrdem( treePtr->esqPtr );
     preOrdem( treePtr->dirPtr );
 } /* fim do if */
 } /* fim da fun��o preOrdem */

 /* inicia travessia da �rvore na p�s-ordem */
 void posOrdem( TreeNodePtr treePtr )
 {
     /* se a �rvore n�o est� vazia, ent�o atravessa */
     if ( treePtr != NULL ) {
         posOrdem( treePtr->esqPtr );
         posOrdem( treePtr->dirPtr );
         printf( "%3d", treePtr->elem );
     } /* fim do if */
 } /* fim da fun��o posOrdem */

 int profundidade( TreeNodePtr treePtr )
 {
     int profEsq = 0;
     int profDir = 0;
     /* se a �rvore n�o est� vazia, ent�o atravessa */
     if ( treePtr != NULL ) {
         if(treePtr->esqPtr != NULL){
            profundidade( treePtr->esqPtr );
            profEsq++;
         }
         if(treePtr -> dirPtr != NULL){
            profundidade( treePtr->dirPtr ) ;
            profDir++;
         }
        // printf( "%3d", treePtr->elem );

         if(profEsq > profDir){
            //printf("\n\nA profundidade da arvore e: %i", profEsq + 1);
            return   profEsq + 1;
         }else{
            //printf("\n\nA profundidade da arvore e: %i", profDir + 1);

            return   profDir + 2;
         }
     } /* fim do if */
 } /* fim da fun��o profundidade */


 int largura( TreeNodePtr treePtr )
 {

     /* se a �rvore n�o est� vazia, ent�o atravessa */
     if ( treePtr != NULL ) {
            return pow(2,profundidade(treePtr)-1);
        }
       return 0;
     } /* fim do if */
/* fim da fun��o Largura */
