/*
-client code: code outside of a class
-protected access modifier: is like private but allows its constituents to be
subclasses of its class. -variables declared b4 the first access modifier are
private by default

-encapsulation: grouping data and methods together. A true encapsulated class is
independent of anything outside the class, making it reusable in another
codebase

-abstraction: separate the interface (its def of ops and params) of a data
structure (DS) from its implementation. You can change how the class methods
work but not what they do (esp the parts required by the client through the
interface). Think of a remote than can control any TV in the world (same
functionality, different methods of implementation. Interface and functionality
of implementation result must remain the same.

-avoid data redundancy: if a new data point can be gotten from other data
points, don't store the new data point.

-composition: using an obj of one class as a dtype in another
*/
#include <iostream>
#include <string>
using namespace std;

struct student {
  int grade;
  int studentID;
  string name;
};

class studentRecord {
public:
  studentRecord();
  studentRecord(int newGrade, int newID, string newName);
  int grade();
  void setGrade(int newGrade);
  int studentID();
  void setStudentID(int newID);
  string name();
  void setName(string newName);
  string letterGrade();

private:
  int _grade;
  int _studentID;
  string _name;
  bool isValidGrade(int grade);
};

bool studentRecord::isValidGrade(int grade) {
  if ((grade >= 0) && (grade <= 100))
    return true;
  else
    return false;
}
int studentRecord::grade() { return _grade; }
string studentRecord::name() { return _name; }
int studentRecord::studentID() { return _studentID; }

void studentRecord::setGrade(int newGrade) {
  if (isValidGrade(newGrade))
    _grade = newGrade;
}

void studentRecord::setStudentID(int id) {
  if (id > 0)
    _studentID = id;
}
void studentRecord::setName(string name) { _name = name; }
studentRecord::studentRecord(int newGrade, int newID, string newName) {
  setGrade(newGrade);
  setStudentID(newID);
  setName(newName);
}

string studentRecord::letterGrade() {
  const int NUMBER_CATEGORIES = 11;
  const string GRADE_LETTER[] = {"F",  "D", "D+", "C-", "C", "C+",
                                 "B-", "B", "B+", "A-", "A"};
  const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
  int category = 0;
  while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
    category++;
  return GRADE_LETTER[category - 1];
}

class studentCollection {
private:
  struct studentNode {
    studentRecord studentData;
    studentNode *next;
  };

public:
  studentCollection();
  void addRecord(studentRecord newStudent);
  studentRecord recordWithNumber(int idNum);
  void removeRecord(int idNum);

private:
  typedef studentNode *studentList;
  studentList _listHead;
};

studentCollection::studentCollection() { _listHead = NULL; }
void studentCollection::addRecord(studentRecord newStudent) {
  studentNode *newNode = new studentNode;
  newNode->studentData = newStudent;
  newNode->next = _listHead;
  _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum) {
  studentNode *loopPtr = _listHead;
  while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum) {
    loopPtr = loopPtr->next;
  }
  if (loopPtr == NULL) {
    studentRecord dummyRecord(-1, -1, "");
    return dummyRecord;
  } else {
    return loopPtr->studentData;
  }
}

void studentCollection::removeRecord(int idNum) {
  studentNode *loopPtr = _listHead;
  studentNode *trailing = NULL;
  while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum) {
    trailing = loopPtr;
    loopPtr = loopPtr->next;
  }
  if (loopPtr == NULL)
    return;
  if (trailing == NULL) {
    _listHead = _listHead->next;
  } else {
    trailing->next = loopPtr->next;
  }
  delete loopPtr;
}