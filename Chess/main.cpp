//
//  main.cpp
//  Chess
//
//  Created by Ryan Yao on 5/12/22.
//

#include <iostream>
#include <vector>
#include <memory>
#include <assert.h>


//No copy constructor so we will use move assignment
class Piece{
public:
    Piece(int side_in, bool king_in, int row_in, int col_in) : side(side_in), king(king_in),
    row(row_in), col(col_in){}
    virtual int move(int, int) = 0;
    virtual void flood(std::vector<std::vector<int>>&board) = 0;
    bool isKing(){
        return king;
    }
    int getSide(){
        return side;
    }
    std::pair<int,int> getPosition(){
        return {this->row, this->col};
    }
    static bool inBounds(int row, int col){
        if(row < 0 || row > 7 || col < 0 || col > 7){
            return false;
        }
        return true;
    }
    virtual ~Piece(){
        
    }
protected:
    int side = 0;
    bool king = false;
    int row = 0;
    int col = 0;
};
std::unique_ptr<Piece> board[8][8];
class Pawn : public Piece{
public:
    Pawn(int side_in, int row_in, int col_in)
        : Piece(side_in, false, row_in, col_in){}
    
    int move(int i, int j) override {
        if(getSide() == 1){
            if(i == row +1 && j == col){
                board[i][j] = std::move(board[row][col]);
                row++;
                return 1;
            }
        }
        else{
            
        }
        return 0;
    }
    void flood(std::vector<std::vector<int>>&board) override {}
};

class Knight: public Piece{
public:
    Knight(int side_in, int row_in, int col_in) : Piece(side_in, false, row_in, col_in){}
    int move(int i, int j) override {
        return 0;
    }
    void flood(std::vector<std::vector<int>>&board) override {}
};

class Rook: public Piece{
public:
    Rook(int side_in, int row_in, int col_in) : Piece(side_in, false, row_in, col_in){}
    int move(int i, int j) override {
        return 0;
    }
    void flood(std::vector<std::vector<int>>&board) override {}
};

class Bishop : public Piece{
public:
    Bishop(int side_in, int row_in, int col_in) : Piece(side_in, false, row_in, col_in){}
    int move(int i, int j) override {
        return 0;
    }
    void flood(std::vector<std::vector<int>>&board) override {}
};

class Queen : public Piece{
public:
    Queen(int side_in, int row_in, int col_in) : Piece(side_in, false, row_in, col_in){}
    int move(int i, int j) override {
        return 0;
    }
    void flood(std::vector<std::vector<int>>&board) override {
        
    }
};

class King : public Piece{
public:
    King(int side_in, int row_in, int col_in) : Piece(side_in, false, row_in, col_in){}
    int move(int i, int j) override {
        if(i -row <= 1 && j - col <= 1 && inBounds(i, j)
           && (board[i][j] == nullptr || board[i][j]->getSide() != this->getSide())){
            board[i][j] = std::move(board[row][col]);
            return 1;
        }
        return 0;
    }
    void flood(std::vector<std::vector<int>>&board) override {
        for(int i = row-1; i <= row+1; i++){
            for(int j = col -1; j <= col +1; j++){
                if(inBounds(i, j)){
                    board[i][j] = 1;
                }
            }
        }
    }
};



//White is side 1, black is side 0
//Board is going to be white at the bottom and black on top
void init(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = nullptr;
        }
    }
    for(int i = 0; i < 8; i++){
        board[1][i] = std::make_unique<Pawn>(1, 1, i);
        board[6][i] = std::make_unique<Pawn>(0, 6, i);
    }
    board[0][4] = std::make_unique<King>(1, 0, 4);
    board[7][4] = std::make_unique<King>(0, 7, 4);
    
    board[0][0] = std::make_unique<Rook>(1, 0, 0);
    board[7][0] = std::make_unique<Rook>(0, 7, 0);
    board[0][7] = std::make_unique<Rook>(1, 0, 7);
    board[7][7] = std::make_unique<Rook>(0, 7, 7);
    
    board[0][3] = std::make_unique<Queen>(1, 0, 3);
    board[7][3] = std::make_unique<Queen>(0, 7, 3);
    
    board[0][1] = std::make_unique<Knight>(1, 0, 1);
    board[7][1] = std::make_unique<Knight>(0, 7, 1);
    
    board[0][2] = std::make_unique<Bishop>(1, 0, 2);
    board[7][2] = std::make_unique<Bishop>(0, 7, 2);
    
    board[0][5] = std::make_unique<Bishop>(1, 0, 5);
    board[7][5] = std::make_unique<Bishop>(0, 7, 5);
    
    board[0][6] = std::make_unique<Knight>(1, 0, 6);
    board[7][6] = std::make_unique<Knight>(0, 7, 6);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int turn = 0;
    init();
    std::cout<<board[6][0]->getSide()<<std::endl;
    std::cout << "New Chess Game!\n";
    std::cout << board[0][4]->move(1,4)<<std::endl;
    std::cout<<board[1][4]->move(2,4);
    std::cout << board[0][4]->move(1,4)<<std::endl;
    return 0;
}



