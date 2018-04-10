#include <iostream>
#include <map>
#include <iterator>
using namespace std;

static unsigned int number_id = 1, num_of_mem = 0;

class Member{

    private:
    unsigned int n_ID;
    map <unsigned int, Member*> followed_by; // map for who is following me
    map <unsigned int, Member*> following;// map for who i'm following after

    void add_followed(Member &obj){ followed_by.insert(pair<unsigned int, Member*>(obj.get_ID(), &obj)); } // adding me to member's map of followed_by
    void erase_followed(unsigned int id){ followed_by.erase(id); }  // helping function - erasing me of member's map of followed_by
    void erase_following(unsigned int id){ following.erase(id); }  // helping destructor to erase me of all members maps of followed_by

    public:
    Member(){  // Constructor
      n_ID = number_id++;
      num_of_mem++;}

    ~Member(){  // Destructor
      for ( unsigned i = 0; i < following.bucket_count(); ++i){
        for ( auto it = following.cbegin(i); it!= following.cend(i); ++it ){
          unfollow(*(it-> second));
        }
      }
      
      for ( unsigned i = 0; i < followed_by.bucket_count(); ++i){
        for ( auto it = followed_by.cbegin(i); it!= followed_by.cend(i); ++it ){
          (it-> second)-> erase_following(n_ID);
        }
      }
	    
      num_of_mem--; }

    unsigned int get_ID() {return n_ID;} // gives my id number
    int numFollowers() { return followed_by.size();}  // gives map's size of how many members are following me
    int numFollowing() { return following.size();}  // gives map's size of how many members i'm following after

    void follow(Member &obj) {  // follow after another member
      if(obj.get_ID() != this->n_ID ){
          obj.add_followed(*this);
          following.insert(pair<unsigned int, Member*>(obj.get_ID(), &obj));
      }
    }

    void unfollow(Member &obj) {  // unfollow a member
        obj.erase_followed(n_ID);
        following.erase(obj.get_ID());
    }

    static unsigned int count(void){ return num_of_mem;}  // function gives how many members are active
    
};
