#include <8051.h>

void main() {
	int i;
	char keys[3][5] = {
	{'A', 'B', 'C', 'D', 'E'},
	{'F', 'G', 'H', 'I', 'J'},
	{'K', 'L', 'M', 'N', ' '}
	};
	int state[3][5] = {
	{1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1}
	};

	P0 = 0x38;
	P2 = 0x1;
	P2 = 0x0;

	P0 = 0x80;
	P2 = 0x1;
	P2 = 0x0;
	P3 = 0x0;
	
	while(1) {
		P10 = 0;
		if (P13==0) state[0][4]=0;
		else if (state[0][4]==0) {
			P0=keys[0][4]; // E
			P2=0x3; 
			P2=0x2;
			state[0][4]=1;
		}
		if (P14==0) state[0][3]=0;
		else if (state[0][3]==0) {
			P0=keys[0][3]; // D
			P2=0x3; 
			P2=0x2;
			state[0][3]=1;
		}
		if (P15==0) state[0][2]=0;
		else if (state[0][2]==0) {
			P0=keys[0][2]; // C
			P2=0x3; 
			P2=0x2;
			state[0][2]=1;
		}
		if (P16==0) state[0][1]=0;
		else if (state[0][1]==0) {
			P0=keys[0][1]; // B
			P2=0x3; 
			P2=0x2;
			state[0][1]=1;
		}
		if (P17==0) state[0][0]=0;
		else if (state[0][0]==0) {
			P0=keys[0][0]; // A
			P2=0x3; 
			P2=0x2;
			state[0][0]=1;
		}
		P10 = 1;

		P11 = 0;
		if (P13==0) state[1][4]=0;
		else if (state[1][4]==0) {
			P0=keys[1][4]; // J
			P2=0x3; 
			P2=0x2;
			state[1][4]=1;
		}
		if (P14==0) state[1][3]=0;
		else if (state[1][3]==0) {
			P0=keys[1][3]; // I
			P2=0x3; 
			P2=0x2;
			state[1][3]=1;
		}
		if (P15==0) state[1][2]=0;
		else if (state[1][2]==0) {
			P0=keys[1][2]; // H
			P2=0x3; 
			P2=0x2;
			state[1][2]=1;
		}
		if (P16==0) state[1][1]=0;
		else if (state[1][1]==0) {
			P0=keys[1][1]; // G
			P2=0x3; 
			P2=0x2;
			state[1][1]=1;
		}
		if (P17==0) state[1][0]=0;
		else if (state[1][0]==0) {
			P0=keys[1][0]; // F
			P2=0x3; 
			P2=0x2;
			state[1][0]=1;
		}
		P11 = 1;

		P12 = 0;
		if (P13==0) state[2][4]=0;
		else if (state[2][4]==0) {
			P0=0x01; 
			P2=0x1; 
			P2=0x0;
			state[2][4]=1;
		}
		if (P14==0) state[2][3]=0;
		else if (state[2][3]==0) {
			P0=keys[2][3]; // N
			P2=0x3; 
			P2=0x2;
			state[2][3]=1;
		}
		if (P15==0) state[2][2]=0;
		else if (state[2][2]==0) {
			P0=keys[2][2]; // M
			P2=0x3; 
			P2=0x2;
			state[2][2]=1;
		}
		if (P16==0) state[2][1]=0;
		else if (state[2][1]==0) {
			P0=keys[2][1]; // L
			P2=0x3; 
			P2=0x2;
			state[2][1]=1;
		}
		if (P17==0) state[2][0]=0;
		else if (state[2][0]==0) {
			P0=keys[2][0]; // K
			P2=0x3; 
			P2=0x2;
			state[2][0]=1;
		}
		P12 = 1;
	}
}
