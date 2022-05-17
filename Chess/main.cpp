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
    Piece(int side_in, bool king_in) : side(side_in), king(king_in){}
    virtual int move() = 0;
    virtual void flood(std::vector<std::vector<int>>&board) = 0;
    bool isKing(){
        return king;
    }
    int getside(){
        return side;
    }
    virtual ~Piece(){
        
    }
protected:
    int side = 0;
    bool king = false;
};

class Pawn : public Piece{
public:
    Pawn(int side_in) : Piece(side_in, false){}
    int move() override {
        return 0;
    }
    void flood(std::vector<std::vector<int>>&board) override {}
};

class Knight: public Piece{
public:
    Knight(int side_in) : Piece(side_in, false){}
    int move() override {
        return 0;
    }
    void flood(std::vector<std::vector<int>>&board) override {}
};

class Rook: public Piece{
public:
    int move() override {
        return 0;
    }
    void flood(std::vector<std::vector<int>>&board) override {}
};

class Bishop : public Piece{
public:
    int move() override {
        return 0;
    }
    void flood(std::vector<std::vector<int>>&board) override {}
};

class Queen : public Piece{
public:
    int move() override {
        return 0;
    }
    void flood(std::vector<std::vector<int>>&board) override {}
};

class King : public Piece{
public:
    
    int move() override {
        return 0;
    }
    void flood(std::vector<std::vector<int>>&board) override {}
};

std::unique_ptr<Piece> board[8][8];


//White is side 1, black is side 0
//Board is going to be white at the bottom and black on top
void init(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = nullptr;
        }
    }
    for(int i = 0; i < 8; i++){
        board[6][i] = std::make_unique<Pawn>(1);
        board[1][i] = std::make_unique<Pawn>(0);
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



