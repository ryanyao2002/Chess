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
    virtual void move() = 0;
    virtual ~Piece(){
        
    }
};

class Pawn : Piece{
public:
    void move(){
        return;
    }
};

class Knight: Piece{
public:
    void move(){
        return;
    }
};

class Rook: Piece{
public:
    void move(){
        return;
    }
};

std::vector<std::vector<Piece>>board;

int main(int argc, const char * argv[]) {
    // insert code here...
    int turn = 0;
    Pawn c = Pawn();
    std::cout << "New Chess Game!\n";
    return 0;
}



