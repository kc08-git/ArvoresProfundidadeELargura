 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <math.h>

 /* estrutura autorreferenciada */
 struct treeNode {
 struct treeNode *esqPtr; /* ponteiro para subárvore esquerda */
 int elem; /* valor do nó */
 struct treeNode *dirPtr; /* ponteiro para subárvore direita */
 }; /* fim da estrutura treeNode */

 typedef struct treeNode TreeNode; /* sinônimo para struct treeNode */
 typedef TreeNode *TreeNodePtr; /* sinônimo para TreeNode* */

/* protótipos */
 void inserir( TreeNodePtr *treePtr, int value );
 void emOrdem( TreeNodePtr treePtr );
 void preOrdem( TreeNodePtr treePtr );
 void posOrdem( TreeNodePtr treePtr );
 int profundidade( TreeNodePtr treePtr );
 int largura( TreeNodePtr treePtr );

 int main(){

     int i; /* contador para loop de 1 a 10 */
     int item; /* variável para manter valores aleatórios */
     TreeNodePtr rootPtr = NULL; /* árvore inicialmente vazia */

     srand( time( NULL ) );
     printf( "Os numeros sendo colocados na arvore sao:\n" );

     /* insere valores aleatórios entre 0 e 14 na árvore */
     for ( i = 1; i <= 10; i++ ) {
         item = rand() % 15;
         printf( "%3d", item );
         inserir( &rootPtr, item );
    } /* fim laço for */

    /* atravessa a árvore preOrdem */
     printf( "\n\nA travessia na pre-ordem ee:\n" );
     preOrdem( rootPtr );

     /* atravessa a árvore emOrdem */
     printf( "\n\nA travessia na ordem ee:\n" );
     emOrdem( rootPtr );

     /* atravessa a árvore posOrdem */
     printf( "\n\nA travessia na pós-ordem ee:\n" );
     posOrdem( rootPtr );

     /* profundidade da árvore*/

     printf( "\n\n A profundidade ee: %i \n", profundidade( rootPtr ));

     printf( "\n\n A profundidade ee: %i \n", largura( rootPtr ));

     return 0; /* indica conclusão bem-sucedida */

 }/* Fim do main*/

 /* insere nó na árvore */
 void inserir( TreeNodePtr *treePtr, int value )
 {
     /* se árvore estiver vazia */
     if ( *treePtr == NULL ) {
         *treePtr = malloc( sizeof( TreeNode ) );

         /* se a memória foi alocada, então atribui dados */
        if ( *treePtr != NULL ) {
             ( *treePtr )->elem = value;
             ( *treePtr )->esqPtr = NULL;
             ( *treePtr )->dirPtr = NULL;
        } /* fim do if */
     else {
         printf( "%d não inserido. Não há memória disponível.\n", value );
         } /* fim do else */
     } /* fim do if */
     else { /* árvore não está vazia */
        /* dado a inserir é menor que dado no nó atual */
         if ( value < ( *treePtr )->elem ) {
            inserir( &( ( *treePtr )->esqPtr ), value );
         } /* fim do if */

         /* dado a inserir é maior que dado no nó atual */
         else if ( value > ( *treePtr )->elem ) {
            inserir( &( ( *treePtr )->dirPtr ), value );
         } /* fim do else if */
         else { /* valor de dado duplicado é ignorado */
            printf( "dup" );
         } /* fim do else */
    } /* fim do else */
 }

 /* inicia travessia da árvore na ordem */
 void emOrdem( TreeNodePtr treePtr )
 {
     /* se árvore não está vazia, então atravessa */
     if ( treePtr != NULL ) {
     emOrdem( treePtr->esqPtr );
     printf( "%3d", treePtr->elem );
     emOrdem( treePtr->dirPtr );
     } /* fim do if */
} /* fim da função emOrdem */

 /* inicia travessia da árvore na pré-ordem */
 void preOrdem( TreeNodePtr treePtr )
 {
 /* se a árvore não está vazia, então atravessa */
 if ( treePtr != NULL ) {
     printf( "%3d", treePtr->elem );
     preOrdem( treePtr->esqPtr );
     preOrdem( treePtr->dirPtr );
 } /* fim do if */
 } /* fim da função preOrdem */

 /* inicia travessia da árvore na pós-ordem */
 void posOrdem( TreeNodePtr treePtr )
 {
     /* se a árvore não está vazia, então atravessa */
     if ( treePtr != NULL ) {
         posOrdem( treePtr->esqPtr );
         posOrdem( treePtr->dirPtr );
         printf( "%3d", treePtr->elem );
     } /* fim do if */
 } /* fim da função posOrdem */

 int profundidade( TreeNodePtr treePtr )
 {
     int profEsq = 0;
     int profDir = 0;
     /* se a árvore não está vazia, então atravessa */
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
 } /* fim da função profundidade */


 int largura( TreeNodePtr treePtr )
 {

     /* se a árvore não está vazia, então atravessa */
     if ( treePtr != NULL ) {
            return pow(2,profundidade(treePtr)-1);
        }
       return 0;
     } /* fim do if */
/* fim da função Largura */
