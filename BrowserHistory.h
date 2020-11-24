 #pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>     // std::next, std::prev
#include <list>
#include "webPage.h"

using std::string;
using std::ifstream;

class BrowserHistory {
public:
    BrowserHistory();

    void visitSite(string url, size_t filesize);
    void backButton();
    void forwardButton();

    void readFile(string fileName);

    string currentUrl();
    size_t currentPageSize();
    size_t getHistoryLength();

private:
  // TO BE COMPLETED
  std::list<webPage> myList;
  std::list<webPage>::iterator nowVisiting;
};


BrowserHistory::BrowserHistory() {
  nowVisiting = myList.begin();
}

void BrowserHistory::backButton(){
  if(nowVisiting != myList.begin()) {
    nowVisiting--;
  }
}

void BrowserHistory::forwardButton() {
  if(nowVisiting != myList.end()) {
    nowVisiting++;
  }
}

void BrowserHistory::visitSite(string url, size_t fileSize){
  nowVisiting->_url = url;
  nowVisiting->_fileSize = fileSize;
}

string BrowserHistory::currentUrl() {
  if(myList.empty()){
    return "";
  } else {
    return nowVisiting->_url;
  }

}


size_t BrowserHistory::currentPageSize() {
  if(myList.empty()){
    return 0;
  } else {
    return nowVisiting->_fileSize;
  }
}

size_t BrowserHistory::getHistoryLength() {
/*  size_t x = 0;
  std::list<webPage>::iterator it;
  for (it = myList.begin(); it != myList.end(); it++){
    x++;
  }
  return x; */
  if(myList.empty()){
    return 0;
  } else {
    return myList.size();
  }
}

void BrowserHistory::readFile(string fileName) {
  webPage wb;
  string myString;

  ifstream myFile(fileName);
  while (myFile >> myString){
    if(myString == "visit") {
      myFile >> wb._url;
      myFile >> wb._fileSize;
    } else if (myString == "back") {
      myFile >> myString;
    } else if (myString == "forward") {
      myFile >> myString;
    }
  }
}
