//
//  main.cpp
//  Chess
//
//  Created by Ryan Yao on 5/12/22.
//

#include <iostream>
#include <vector>
#include <memory>

class Piece{
public:
    Piece(int side_in) : side(side_in){}
    virtual int move() = 0;
    int getside(){
        return side;
    }
    virtual ~Piece(){
        
    }
protected:
    int side =0;
};

class Pawn : public Piece{
public:
    Pawn(int side_in) : Piece(side_in){}
    int move() override {
        return 0;
    }
};

class Knight: public Piece{
public:
    int move(){
        return 0;
    }
};

class Rook: public Piece{
public:
    int move(){
        return 0;
    }
};

class Bishop : public Piece{
public:
    int move(){
        return 0;
    }
};

class Queen : public Piece{
public:
    int move(){
        return 0;
    }
};

class King : public Piece{
public:
    
    int move(){
        return 0;
    }
};

std::unique_ptr<Piece> board[8][8];


//White is side 1, black is side 0
//Board is going to be white at the bottom and black on top
void init(){
    for(int i = 0; i < 8; i++){
        board[6][i] = std::make_unique<Pawn>(1);
        board[1][i] = std::make_unique<Pawn>(1);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int turn = 0;
    init();
    std::cout<<board[6][0]->getside()<<std::endl;
    std::cout << "New Chess Game!\n";
    return 0;
}



