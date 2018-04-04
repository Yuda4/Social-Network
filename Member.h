#include <iostream>
#include <map>
#include <iterator>
using namespace std;

static unsigned int number_id = 1, num_of_mem = 0;

class Member{

    private:
    unsigned int n_ID;
    map <unsigned int, Member*> followed_by; //who is following me
    map <unsigned int, Member*> following;//following after

    public:
    Member(){
      n_ID = number_id++;
      num_of_mem++;}

    ~Member(){
      map<unsigned int, Member*>::iterator it;

      for ( it = following.begin(); it != following.end(); it++ )
        unfollow(*it);
      num_of_mem--; }

    unsigned int get_ID() {return n_ID;}
    int numFollowers() { return followed_by.size();}
    int numFollowing() { return following.size();}

    void follow(Member &obj) {
        obj.add_followed(*this);
        following.insert(pair<unsigned int, Member*>(obj.get_ID(), &obj));}

    void unfollow(Member &obj) {
        obj.erase_followed(n_ID);
        following.erase(obj.get_ID());}

    void add_followed(Member &obj){ followed_by.insert(pair<unsigned int, Member*>(obj.get_ID(), &obj)); }

    void erase_followed(unsigned int id){ followed_by.erase(id); }

    static unsigned int count(void){ return num_of_mem;}
};
