#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int dice_num[4];
int gamePoints(void);
void getNum(void);

int main(void){
    int point;
    srand(time(NULL));
    for (int i=0;i<5;i++){
        getNum();
            point=gamePoints();
            cout << dice_num[0] << " " <<dice_num[1] << " " <<dice_num[2]<< " " <<dice_num[3]<<" ����=" << point << "��"<<"\n";
    }
    return 0;
}

int gamePoints(void){
    int point=0;
    if(dice_num[0]==dice_num[1] && dice_num[1]==dice_num[2] &&dice_num[2]==dice_num[3])
        point=100;
        //100�� 
    else if((dice_num[0]==dice_num[1]&&dice_num[1]==dice_num[2]&&dice_num[3]!=dice_num[0]&&dice_num[3]!=dice_num[1]&&dice_num[3]!=dice_num[2])||
		(dice_num[1]==dice_num[2]&&dice_num[2]==dice_num[3]&&dice_num[0]!=dice_num[1]&&dice_num[0]!=dice_num[2]&&dice_num[0]!=dice_num[3])||
		(dice_num[2]==dice_num[3]&&dice_num[3]==dice_num[0]&&dice_num[1]!=dice_num[2]&&dice_num[1]!=dice_num[3]&&dice_num[1]!=dice_num[0]))
    	point=0;
    	//0�����Ҧ����p 
    else if(dice_num[0]==dice_num[1] && dice_num[2]==dice_num[3]) 
		point=dice_num[2]+dice_num[3];
    else if(dice_num[0]==dice_num[1])
        point=dice_num[2]+dice_num[3];              
    else if(dice_num[1]==dice_num[2])
        point=dice_num[0]+dice_num[3];                
	else if(dice_num[2]==dice_num[3])
        point=dice_num[0]+dice_num[1];
        //��L����
    return point;
}

void getNum(void){
    int a;
    for(int i=0;i<=5;i++){
        dice_num[i]=1+rand()%6;//�Y��l
    }
    for(int i=0;i<=5;i++){ //�p�ƨ�j
    	for(int j=i;j<=5;j++){
            if( dice_num[i] > dice_num[j] ) {
                a=dice_num[i];
                dice_num[i]=dice_num[j];
                dice_num[j]=a;
            }
        }
	}
}


