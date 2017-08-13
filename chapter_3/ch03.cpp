# include <algorithm>
# include <iomanip>
# include <ios>
# include <iostream>
# include <string>
# include <vector>
using namespace std;

vector<double> find_quartiles(vector<double> vec) {

  double lq, median, uq;
  vector<double> result;

  typedef vector<double>::size_type vec_sz;
  vec_sz N = vec.size();

  sort(vec.begin(), vec.end()); // sort the input vector in non decreasing order

  int n_mod_4 = N % 4;

  if(N == 0) {
    cout << "Please enter at least one homework grade." << endl;
    return result;
  } 

  else if(N == 1) { // first edge case N==1 where all lq, median, uq are the same
    lq = vec[0];
    median = vec[0];
    uq = vec[0];
  }
  else if(N == 2) { // second edge case where N==2 
    lq = vec[0];
    median = (vec[0] + vec[1]) / 2.0;
    uq = vec[1];
  } 

  // below are the four possible patterns corresponding to N%4==0, N%4==1, N%4==2, N%4==3 
  else if(n_mod_4 == 0) {
    lq = (vec[N/4 - 1] + vec[N/4]) / 2.0;
    median = (vec[N/2 - 1] + vec[N/2]) / 2.0;
    uq = (vec[N * 3.0/4 - 1] + vec[3.0/4 * N]) / 2.0;
  }
  else if(n_mod_4 == 1) {
    lq = (vec[N/4 - 1] + vec[N/4]) / 2.0;
    median = vec[N/2];
    uq = (vec[N * 3.0/4 + 1] + vec[3.0/4 * N]) / 2.0;
  } 
  else if(n_mod_4 == 2) {
    lq = vec[N/4];
    median = (vec[N/2 - 1] + vec[N/2]) / 2.0;
    uq = vec[N * 3.0/4];
  }
  else if(n_mod_4 == 3) {
    lq = vec[N/4];
    median = vec[N/2];
    uq = vec[N * 3.0/4];
  }
  else {
    cout << "Unrecognised pattern occured." << endl;
    return result;
  }

  result.push_back(lq);
  result.push_back(median);
  result.push_back(uq);

  return result;
}

// find the median of a vector or doubles  
double find_median(vector<double> vec) { 

  typedef vector<double>::size_type vec_sz;
  vec_sz size = vec.size();

  sort(vec.begin(), vec.end()); // sort in nondecreasing order

  int mid = size/2;
  
  return (size % 2 == 0) ?  (vec[mid] + vec[mid-1]) / 2 
                                  : vec[mid];
}

// find the median of a vector or doubles  
double find_lower_quartile(vector<double> vec) { 

  typedef vector<double>::size_type vec_sz;
  vec_sz size = vec.size();

  sort(vec.begin(), vec.end()); // sort in nondecreasing order

  int index = size/4;
  double median = (size % 2 == 0) ?  (vec[index] + vec[index-1]) / 2 
                                  : vec[index];
  return median;                                
}

// find the median of a vector or doubles  
double find_upper_quartile(vector<double> vec) { 

  typedef vector<double>::size_type vec_sz;
  vec_sz size = vec.size();

  sort(vec.begin(), vec.end()); // sort in nondecreasing order

  int index = 0.75 * size;
  double median = (size % 2 == 0) ?  (vec[index] + vec[index-1]) / 2   
                                  : vec[index];
  return median;                                
}

void median_grade() {
  cout << "Please enter your midterm and final grades seperated " 
          "by a space and press enter: " << endl;

  double midterm, final;
  cin >> midterm >> final;

  cout << "Please enter your homework grades seperated " 
          "by spaces and then press ctrl+D: " << endl;

  double x;
  vector<double> hw_grades;

  while(cin >> x)
    hw_grades.push_back(x);

  typedef vector<double>::size_type vec_sz;
  vec_sz size = hw_grades.size();

  if(size == 0) {
    cout << "Please enter at least one homework grade." << endl;
    return;
  }

  double median = find_median(hw_grades);

  streamsize prec = cout.precision();

  cout << "Your final grade is: " << setprecision(3) 
    << 0.2 * midterm + 0.4 * final + 0.4 * median << setprecision(prec) << endl;

}

void q02() {

  cout << "Please enter your homework grades seperated " 
          "by spaces and then press ctrl+D: " << endl;

  double x;
  vector<double> grades;

  while(cin >> x)
    grades.push_back(x);

  vector<double> quartiles = find_quartiles(grades);

  cout << "Lower quartile :" << quartiles[0] << endl;
  cout << "Median :" << quartiles[1] << endl;
  cout << "Upper quartile :" << quartiles[2] << endl;
}

// Write a program to count how many times each distinct word appears in its input.
void q03() {
  cout << "Please enter a string of words seperated by spaces: " << endl;

  string w;
  vector<string> words;
  
  while(cin >> w)
    words.push_back(w); 

  typedef vector<double>::size_type vec_sz;
  vec_sz N = words.size();

  if(N == 0) {
    cout << "Please enter at least one word." << endl;
    return;
  } 

  sort(words.begin(), words.end()); // sorts strings in alphabetical order

  int count = 0;
  vector<string> distinct_words;
  vector<int> word_counts;

  distinct_words.push_back(words[0]); // add the fist word to distinct words vector
  
  for(int i=0; i<words.size(); ++i) { // for the rest of the words 
    // if word is not the same as the most recently added to distinct words 
    // then add it and add the word count to the end of the word_counts vector
    // reset word count to 1 for the current word
    if(words[i] != distinct_words[distinct_words.size()-1]) { 
      word_counts.push_back(count);
      distinct_words.push_back(words[i]);
      count = 1;
    } else {
      count += 1; // else increase the word count by 1
    }
  }
  // add the word count if the end of the words vector is reached
  word_counts.push_back(count); 

  cout << "The number of times each distinct word appeared" 
       << "in alphabetical order is: " << endl;

  for(int i=0; i<distinct_words.size(); ++i) {
    cout << distinct_words[i] << " appeared " << word_counts[i] << " times." << endl;
  }

}

// write a program to report the length of the longest and shortest string in its input.
void q04() {
  cout << "Please enter a string of words seperated by spaces: " << endl;

  string w;
  vector<string> words;
  
  while(cin >> w)
    words.push_back(w); 

  typedef vector<double>::size_type vec_sz;
  vec_sz N = words.size();

  if(N == 0) {
    cout << "Please enter at least one word." << endl;
    return;
  } 

  string longest = words[0];
  string shortest = words[0];
  
  for(int i=0; i<words.size(); ++i) {
    if(words[i].size() > longest.size()) 
      longest = words[i];
    else if(words[i].size() < shortest.size())
      shortest = words[i];
  }

  cout << "The longest word entered is: " << longest << " which is " 
       << longest.size() << " characters long." << endl; 
      
  cout << "The shortest word entered is: " << shortest << " which is " 
       << shortest.size() << " characters long." << endl; 
}

void q05() {

  vector<string> names;
  string name;
  
  vector<double> mean_grades; 

  const int number_of_grades = 5;

  cout << "Please enter your name: " << endl;

  while(cin >> name) {
    names.push_back(name);
    cout << "Please enter " << number_of_grades << " homework grades." << endl;

    double x;
    vector<double> grades;

    for(int i=0; i<number_of_grades; ++i) {
      cin >> x;
      grades.push_back(x);
    }

    typedef vector<double>::size_type vec_sz;
    vec_sz size = grades.size();

    if(size == 0) {
      cout << "Please enter at least one homework grade." << endl;
      return;
    } else {
      double sum = 0;
      for(int i=0; i<grades.size(); ++i)
        sum += grades[i];
      mean_grades.push_back(sum / grades.size());
    }
    cout << "Enter another name or ctrl+D to move on." << endl;
  }

  streamsize prec = cout.precision();

  for(int i=0; i<names.size(); ++i) {
      cout << names[i] << " scored an average mark of " << setprecision(3) 
           << mean_grades[i] << setprecision(prec) << endl;
  }

}

void q06() {

  cout << "Please enter your first name: ";
  string name;
  // ask for and read the student's name cout << "Please enter your first name: "; string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;
   
  // ask for and read the midterm and final grades
  cout << "Please enter your midterm and final exam grades: "; double midterm, final;
  cin >> midterm >> final;
  // ask for the homework grades
  cout << "Enter all your homework grades, "
               "followed by end-of-file: ";
  // the number and sum of grades read so far int count = 0;
  double sum = 0;
  int count = 0;
  // a variable into which to read double x;
  double x;

  while(cin >> x)
    ++count;
    sum += x; 

  if(count == 0) {
    cout << "You must enter at least one grade." << endl;
    return;
  }
  
  // write the result
  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
  << 0.2 * midterm + 0.4 * final + 0.4 * sum / count << setprecision(prec) << endl;

}

int main(){
  q06();
  return 0;
}
