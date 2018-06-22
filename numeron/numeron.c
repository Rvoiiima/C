#include <stdio.h>
#include <stdlib.h>

int check(int n) {
    int a, b, c;


    a = n/100;
    b = n%100/10;
    c = n%10;
    return (n >= 12 && n <= 987 && a != b && b != c&& c != a);
}



int main(void) {
    int user1[3];
    int user2[3];
    int m1,m2;
    int a,b,c;
    int eat = 0, byte = 0;

    printf("-----------------------Welcome to NumerOn Game!---------------------\n");
    printf("相手が最初に入力した3桁の数字を当てたら勝ち。数字を推測した後に出るeat, byteのヒントをもとに、相手の数字を当ててください。\n\n\n");
    printf("eat:場所も数字も正しい数字の個数です。\n\n");
    printf("byte:数字は正しいけど場所が違う数字の個数です。\n\n");
    printf("Set Menu プレイヤーごとに3桁の数字をセットしてください。\n\n各位は、それぞれ異なる数字にしなければいけません。\n\n\n");
    printf("bad example:992, 001 , 121, 334\n");



    while(1){
        printf("input player1(3 numbers):");
        scanf("%d",&m1);
        if(check(m1)) break;
        printf("各位に、同じ数字が2つ以上あってはいけません。\n");
    }
    
    user1[2] = m1/100;
    user1[1] = m1%100/10;
    user1[0] = m1%10;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");


    while(1){
        printf("input player2(3 numbers):");
        scanf("%d",&m2);
        if(check(m2)) break;
        printf("各位に、同じ数字が2つ以上あってはいけません。\n");
    }
    
    user2[2] = m2/100;
    user2[1] = m2%100/10;
    user2[0] = m2%10;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    
    printf("---------------------------------------------------------------------\n");
    printf("Game Start!!\n");
    while(1) {

        while(1){
            printf("Turn of Player 1:");
            scanf("%d",&m1);
            if(check(m1)) break;
            printf("各位に、同じ数字が2つ以上あってはいけません。\n");
        }

        
        a = m1/100;
        b = m1%100/10;
        c = m1%10;
        
        eat = 0;
        if(a == user2[2]) eat ++;

        if(b == user2[1]) eat ++;

        if(c == user2[0]) eat ++;

        byte = 0;

        if(a == user2[1] || a == user2[0]) byte ++;
        if(b == user2[2] || b == user2[0]) byte ++;
        if(c == user2[1] || c == user2[2]) byte ++;

        if(eat != 3) 
            printf("%d eat - %d byte\n", eat, byte);
        else {
            printf("You Win!\n");
            break;
        }

        while(1){
            printf("Turn of player 2:");
            scanf("%d",&m2);
            if(check(m2)) break;
            printf("各位に、同じ数字が2つ以上あってはいけません。\n");
        }

        
        a = m2/100;
        b = m2%100/10;
        c = m2%10;
        
        eat = 0;
        if(a == user1[2]) eat ++;

        if(b == user1[1]) eat ++;

        if(c == user1[0]) eat ++;

        byte = 0;

        if(a == user1[1] || a == user1[0]) byte ++;
        if(b == user1[2] || b == user1[0]) byte ++;
        if(c == user1[1] || c == user1[2]) byte ++;

        if(eat != 3) 
            printf("%d eat - %d byte\n", eat, byte);
        else {
            printf("You Win!\n");
            break;
        }
    }
    return 0;
}
