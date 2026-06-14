#include <string>

#include <vector>

#include <deque>



#define SHIFT_ROW "ShiftRow"

#define ROTATE "Rotate"



using namespace std;



int R, C;

deque<int> leftCol;

deque<int> rightCol;

deque<deque<int>> midRows;



void ShiftRow()

{

    leftCol.push_front(leftCol.back());

    leftCol.pop_back();

    

    rightCol.push_front(rightCol.back());

    rightCol.pop_back();

    

    midRows.push_front(move(midRows.back()));

    midRows.pop_back();

}



void Rotate()

{

    /*

    

    1   2   3   4

    5   6   7   8

    9   10  11  12

    13  14  15  16

    

    ---

    

    5   1   2   3

    9   6   7   4

    13  10  11  8

    14  15  16  12

    

    */

    

    if (C == 2)

    {

        

    }

    

    midRows.front().push_front(leftCol.front());

    leftCol.pop_front();

    

    rightCol.push_front(midRows.front().back());

    midRows.front().pop_back();

    

    midRows.back().push_back(rightCol.back());

    rightCol.pop_back();

    

    leftCol.push_back(midRows.back().front());

    midRows.back().pop_front();

}



vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {

    vector<vector<int>> answer;

    

    R = rc.size();

    C = rc[0].size();

    

    for (vector<int> row : rc)

    {

        deque<int> midRow;

        

        for (int c = 0; c < C; ++c)

        {

            if (c == 0)

                leftCol.push_back(row[c]);

            else if (c == C - 1)

                rightCol.push_back(row[c]);

            else

                midRow.push_back(row[c]);

        }

        

        midRows.push_back(midRow);

    }

    

    for (string operation : operations)

    {

        if (operation == ROTATE)

            Rotate();

        if (operation == SHIFT_ROW)

            ShiftRow();

    }

    

    for (int r = 0; r < R; ++r)

    {

        vector<int> answerRow;

        

        answerRow.push_back(leftCol[r]);

        

        for (int val : midRows[r])

            answerRow.push_back(val);

        

        answerRow.push_back(rightCol[r]);

        

        answer.push_back(answerRow);

    }

    

    return answer;

}