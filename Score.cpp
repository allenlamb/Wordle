//
// Created by Allen Lam on 5/8/22.
//

#include "Score.h"

void Score::setAnswer(std::string word) {
    answer = word;
    std::cout << answer;
}
std::string Score::attemptResult(std::string word) {
    std::string result;
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == answer[i]) {
            result.push_back('g');
        }
        else if (answer.find(word[i])!= std::string::npos) {
            result.push_back('y');
        }
        else {
            result.push_back('n');
        }
    }
    if (result == "ggggg") {
        solve = true;
    }
    shareScore.push_back(result);
    return result;
}

bool Score::isSolve() const {
    return solve;
}

std::string Score::getAnswer() const {
    return answer;
}

void Score::scoreFile(std::string title) {
    std::vector<std::string> score = {"", "", "", "", ""};
    for (int i = 0; i < shareScore.size(); ++i) {
        for (int j = 0; j < 5; ++j) {
            if (shareScore[i][j] == 'g') {
                score[i] += ("🟩");
            } else if (shareScore[i][j] == 'y') {
                score[i] += ("🟨");
            } else if (shareScore[i][j] == 'n') {
                score[i] += ("⬛");
            }
        }
    }
    std::ofstream fout;
    fout.open("wordleScore.txt");
    if (fout.is_open()) {
        fout << title + " " + std::to_string(Wordle::getAttempt()) + "/6" << std::endl << std::endl;
        for (int i = 0; i < Wordle::getAttempt(); ++i) {
            fout << score[i] << std::endl;
        }
    }
        fout.close();
}


