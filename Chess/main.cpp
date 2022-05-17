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
    virtual void move() = 0;
    int getside(){
        return side;
    }
    virtual ~Piece(){
        
    }
public:
    int side =0;
};

class Pawn : public Piece{
public:
    Pawn(int side_in) : Piece(side_in){}
    void move() override {
        return;
    }
    ~Pawn(){}
};

class Knight: public Piece{
public:
    void move(){
        return;
    }
};

class Rook: public Piece{
public:
    void move(){
        return;
    }
};

class Bishop : public Piece{
public:
    void move(){
        return;
    }
};

class Queen : public Piece{
public:
    void move(){
        return;
    }
};

class King : public Piece{
public:
    
    void move(){
        return;
    }
};

std::unique_ptr<Piece> board[8][8];


//White is side 1, black is side 0
//Board is going to be white at the bottom and black on top
void init(){
    board[0][0] = std::make_unique<Pawn>(1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int turn = 0;
    init();
    std::cout<<board[0][0]->getside()<<std::endl;
    std::cout << "New Chess Game!\n";
    return 0;
}



