#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  // このコードは標準入力と標準出力を用いたサンプルコードです。
  // このコードは好きなように編集・削除してもらって構いません。
  // ---
  // This is a sample code to use stdin and stdout.
  // Edit and remove this code as you like.

  string s;
  s = argv[1];

  cout<<s<<endl;

/*
  if(s.find("doc") != string::npos && s.find("img") != string::npos) {
    cout<<"presentation"<<endl;
  }

  } else if(s.find("doc") != s.end()) {
    cout<<"document"<<endl;
  } else if(s.find("img") != s.end()) {
    cout<<"image"<<endl;
  } else {
    cout<<"other"<<endl;
  }
  */

  return 0;
}

