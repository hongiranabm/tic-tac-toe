#include<stdio.h>
#include<stdlib.h>
void print_box(char arr[3][3]){
	system("cls");
	int i, j;
	for(i=0; i<3; i++){
		printf(" --- --- --- \n");
		for(j=0; j<3; j++){
			printf("|");
			printf(" %c ", arr[i][j]);
		}
		printf("|\n");
	}
	printf(" --- --- --- \n");
}


int is_game_over(char arr[3][3]){
	if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && arr[0][0] != ' ')
		return 1;
	if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0] && arr[2][0] != ' ')
		return 1;
	if(arr[0][0]==arr[0][1] && arr[0][1]==arr[0][2] && arr[0][0] != ' ')
		return 1;
	if(arr[0][0]==arr[1][0] && arr[2][0]==arr[1][0] && arr[0][0] != ' ')
		return 1;
	if(arr[2][0]==arr[2][1] && arr[2][1]==arr[2][2] && arr[2][0] != ' ')
		return 1;
	if(arr[0][1]==arr[1][2] && arr[1][2]==arr[2][2] && arr[0][1] != ' ')
		return 1;
	if(arr[1][0]==arr[1][1] && arr[1][1]==arr[1][2] && arr[1][0] != ' ')
		return 1;
	if(arr[0][1]==arr[1][1] && arr[1][1]==arr[2][1] && arr[0][1] != ' ')
		return 1;
	else if(is_it_draw(arr))
		return 2;
	return 0;
}


int is_it_draw(arr[3][3]){
	int i;
	for(i=0; i<3; i++)
			if(arr[i]!=' ')
				return 1;
}



void main()
{
	int i, j, a, b, active_player=1;
	char arr[3][3];
	char player_1[50], player_2[50];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			arr[i][j]=' ';
		}
	}
	printf("Enter player1 name: ");
	scanf("%s", player_1);
	printf("Enter player2 name: ");
	scanf("%s", player_2);
	while(1){
		print_box(arr);
		printf("%s's chance\n", active_player>0 ? player_1 : player_2);
		while (1){
			printf("Enter the coordinates for %c: ", active_player>0 ? 'X' : 'O');
			scanf("%d %d", &a, &b);
			if (arr[a][b]!=' ' || a>2 || b>2 || a<0 || b<0)
				printf("Invalid coordinates!\n");
			else
				break;
		}
		arr[a][b] = active_player>0 ? 'X' : 'O';
		if(is_game_over(arr)==1){
			print_box(arr);
			break;
		}
		else if(is_game_over(arr)==2){
			print_box(arr);
			printf("draw match");
		}
		active_player*=-1;
	}
	if(active_player==1 || active_player==-1)
		printf("%s wins", active_player>0 ? player_1 : player_2);
}
