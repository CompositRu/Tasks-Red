
#include "test_runner.h"
#include "profiler.h"

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

class Learner {
 private:
  set<string> dict;

 public:
  int Learn(const vector<string>& words) {
    int old_size = dict.size();
    dict.insert(words.begin(), words.end());
    return dict.size() - old_size;
  }

  vector<string> KnownWords() {
    return {dict.begin(), dict.end()};
  }
};


int main() {
	  Learner learner;
	  string line;
	  ifstream text_file(R"(C:\Dev\eclipse-workspace\Solving_tasks\Debug\text.txt)");
	  int count_words = 0;
	  LOG_DURATION("test");
	  while (getline(text_file, line)) {
	    vector<string> words;
	    stringstream ss(line);
	    string word;
	    while (ss >> word) {
	      words.push_back(word);
	    }
	    count_words += learner.Learn(words);
	  }
	  cout << count_words << endl;
	  text_file.close();
}
