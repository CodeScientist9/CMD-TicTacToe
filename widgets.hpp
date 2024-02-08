#include <iostream>
#include <windows.h>
#define KEY_UP     72
#define KEY_LEFT   75
#define KEY_RIGHT  77
#define KEY_DOWN   80
#define KEY_ENTER  13
#define BACKSPACE   8
#define CHARX     120
#define CHARO     111
#define CHAR0      48
#define CHAR1      49
#define CHAR2      50
#define CHAR3      51
#define CHAR_A     97
#define CHAR_A_CA  65
#define CHAR_B     98
#define CHAR_B_CA  66
#define CHAR_C     99
#define CHAR_C_CA  67
#define CHAR_R     82
#define CHAR_R_CA 114
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void setpos(int coordX, int coordY) {                     //Sets coordinates              ( positionX , positionY )
    COORD coordinates;
    coordinates.X = coordX;
    coordinates.Y = coordY;
    SetConsoleCursorPosition(hConsole, coordinates);
}
void setcursor(bool visible, DWORD size) {                //Sets cursor on/off            ( 1/0 , 10/0            )
	if(size == 0) {
		size = 20;
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(hConsole,&lpCursor);
}
void setcolor(unsigned char color) {                      //Sets color                    ( hexadecimal code      )
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color );
}
void levelColor(std::string level) {                      //Sets color of level           ( num of level          )
    std::string row1 = "#     1   2   3   4   5     #";
    std::string row2 = "#      6    7   8    9      #";

    for(int i = 0; i < row1.length(); i++) {
        if(row1.at(i) == level.at(0)) {
            setpos(i,3);
            setcolor( 0x03 );
            std::cout << row1.at(i);
            setcolor( 0x07 );
        }
        else {
            setpos(i,3);
            setcolor( 0x07 );
            std::cout << row1.at(i);
        }
    }

    for(int i = 0; i < row2.length(); i++) {
        if(row2.at(i) == level.at(0)) {
            setpos(i,5);
            setcolor( 0x03 );
            std::cout << row2.at(i);
            setcolor( 0x07 );
        }
        else {
            setpos(i,5);
            setcolor( 0x07 );
            std::cout << row2.at(i);
        }
    }

    setpos(0,7);
    std::cout << '\r' << "#=================== ";
    setcolor( 0x07 );
    std::cout << "Return";
    setcolor( 0x07 );
    std::cout << " #";
}
void pvcPvpColor(int pvc, int pvp, int reTurn) {          //Sets choice color             ( hex of choice         )
    setpos(0,3);
    std::cout << '\r' << "#  ";
    setcolor( pvc );
    std::cout << "Player vs Computer";
    setcolor( 0x07 );
    std::cout << "    |  #";

    setpos(0,5);
    std::cout << '\r' << "#  ";
    setcolor( pvp );
    std::cout << "Player vs Player";
    setcolor( 0x07 );
    std::cout << "      |  #";

    setpos(0,7);
    std::cout << '\r' << "#=================== ";
    setcolor( reTurn );
    std::cout << "Return";
    setcolor( 0x07 );
    std::cout << " #";
}
void pvpScorePlay(int s, int p, int reTurn) {             //Sets choice color             ( hex of choice         )
    setpos(0,3);
    std::cout << '\r' << "#   ";
    setcolor( p );
    std::cout << "Play";
    setcolor( 0x07 );
    std::cout << "                 |  #";

    setpos(0,5);
    std::cout << '\r' << "#   ";
    setcolor( s );
    std::cout << "Score";
    setcolor( 0x07 );
    std::cout << "                |  #";

    setpos(0,7);
    std::cout << '\r' << "#=================== ";
    setcolor( reTurn );
    std::cout << "Return";
    setcolor( 0x07 );
    std::cout << " #";
}
void pvcScoreLevel(int s, int l, int reTurn) {            //Sets choice color             ( hex of choice         )
    setpos(0,3);
    std::cout << '\r' << "#   ";
    setcolor( l );
    std::cout << "Levels";
    setcolor( 0x07 );
    std::cout << "               |  #";

    setpos(0,5);
    std::cout << '\r' << "#   ";
    setcolor( s );
    std::cout << "Score";
    setcolor( 0x07 );
    std::cout << "                |  #";

    setpos(0,7);
    std::cout << '\r' << "#=================== ";
    setcolor( reTurn );
    std::cout << "Return";
    setcolor( 0x07 );
    std::cout << " #";
}
void pvcLevelColor(int start, int reTurn) {               //Sets choice color             ( hex of choice         )
    setpos(0,5);
    std::cout << '\r' << "#           ";
    setcolor( start );
    std::cout << "Start";
    setcolor( 0x07 );
    std::cout << "           #";

    setpos(0,7);
    std::cout << '\r' << "#=================== ";
    setcolor( reTurn );
    std::cout << "Return";
    setcolor( 0x07 );
    std::cout << " #";
}
void pvcCharColor(int o, int x) {                         //Sets choice color             ( hex of choice         )
    setpos(15,4);
    setcolor( o );
    std::cout << " O ";

    setpos(11,4);
    setcolor( x );
    std::cout << " X ";
}
void takenSpot() {                                        //Displays taken level          ( NULL                  )
    setpos(30,4);
    std::cout << "That spot";
    setpos(30,5);
    std::cout << "is taken!";
    setpos(33,10);
    std::cout << "   ";
    Sleep(500);
    setpos(30,4);
    std::cout << "         ";
    setpos(30,5);
    std::cout << "         ";
}
void mainColor(int start, int guide) {                    //Sets choice color             ( hex of choice         )
    setpos(0,3);
    std::cout << '\r' << "#           ";
    setcolor( start );
    std::cout << "START";
    setcolor( 0x07 );
    std::cout << "           #";

    setpos(0,6);
    std::cout << '\r' << "#         | ";
    setcolor( guide );
    std::cout << "GUIDE";
    setcolor( 0x07 );
    std::cout << " |         #";
}
void guide1Color(int arrw, int reTurn) {                  //Sets choice color             ( hex of choice         )
    setpos(0,2);
    std::cout << '\r' << "#| Select = Enter        ";
    setcolor( arrw );
    std::cout << ">>";
    setcolor( 0x07 );
    std::cout << " #";

    setpos(0,7);
    std::cout << '\r' << "#=================== ";
    setcolor( reTurn );
    std::cout << "Return";
    setcolor( 0x07 );
    std::cout << " #";
}