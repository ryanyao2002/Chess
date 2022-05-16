//
//  main.cpp
//  Chess
//
//  Created by Ryan Yao on 5/12/22.
//

#include <iostream>
#include <vector>

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
    int side;
};

class Pawn : public Piece{
public:
    Pawn(int side_in) : Piece(side_in){}
    void move(){
        return;
    }
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

std::vector<std::vector<Piece>>board(8, std::vector<Piece>(8));

int main(int argc, const char * argv[]) {
    // insert code here...
    int turn = 0;
    board[0][0] = Pawn(1);
    std::cout << "New Chess Game!\n";
    return 0;
}



