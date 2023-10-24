#include <stdio.h>

char chess[8][8];

void initialChessboard(){

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            chess[i][j] = 0;
        }
    }
    chess[3][3] = chess[4][4] = 2;
    chess[3][4] = chess[4][3] = 1;

}
int judge2(int x, int y, int color){

     int findC;
     if(color == 1){
          findC = 2;
     }
     else{
          findC = 1;
     }


     for(int dx = -1 ; dx <= 1 ; dx++){
         for(int dy = -1 ; dy <=1 ; dy++){
             if(dx == 0 && dy == 0){
                    continue;
              }

              int newX = x+dx;
              int newY = y+dy;

              while(newX >= 0 && newX < 8 && newY >= 0 && newY < 8 && chess[newX][newY] == findC){
                     newX += dx;
                     newY += dy;
                     if(chess[newX][newY] == color){
                         return 1;
                     }
               }
           }
       }
       return 0;
}
void judge1(int x, int y, int color){

    switch(chess[x][y]){
        case 1:
            printf("�ثe���Ѥl�C��O�¦� �A�ҥH����U�l");
            break;

        case 2:
            printf("�ثe���Ѥl�C��O�զ� �A�ҥH����U�l");
            break;
        case 0:
            switch(judge2(x,y,color)){
                case 1:
                    printf("(%d,%d)��U color=%d ���l",x ,y ,color);
                    break;

                case 0:
                    printf("(%d,%d)����U color=%d ���l",x ,y ,color);
                    break;

            }
            break;
    }
}

void printChessboard(){

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            printf("%d ", chess[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int x, y, color,cont = 0;

    initialChessboard();
    printChessboard();

    printf("\n");

    printf("0: ��ܪť� \n1: ��ܶ´� \n2: ��ܥմ�\n");

    while(cont != -1){
            do{
                printf("\n��J���U�Ѫ��y��(x,y) : ");
                scanf("%d %d",&x ,&y);
            }while(x<0 || x>8 || y<0 || y>8);


            printf("�U�Ѫ��C�� : ");
            scanf("%d",&color);

            judge1(x,y,color);

            printf("\n�O�_�~���J�A�O:��J0 ; �_:��J-1\n");
            scanf("%d",&cont);

    }

    return 0;
}
