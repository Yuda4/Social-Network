#include <iostream>
using namespace std;

#include "Member.h"


Member avi, beni, chana;

void test2() {
	Member dana, shlomi;
	cout << "  " << dana.get_ID() << " dana's id test 2" << endl; // 7-> first time  // 9-> second time
	shlomi.follow(dana);
	shlomi.follow(avi);
	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 1-> first time // 0 0-> second time //
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl;  // 2 1-> first time  // 1 1-> second time //
    cout << "  " << shlomi.numFollowers() << " " <<  shlomi.numFollowing() << endl;  //0 2-> first time // 0 2-> second time //
	cout << "  " << Member::count() << " members are at test 2" << endl; // 8-> first time  // 5-> second time//
}

void test1() {
    
	Member dana, adiel, yuda;
	chana.follow(dana);
	avi.follow(adiel);
	dana.follow(avi);
	cout << "  " << dana.get_ID() << " dana's id test 1" << endl; // 4
	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 1
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 1 1
	cout << "  " << adiel.numFollowers() << " " <<  adiel.numFollowing() << endl; // 1 0
	cout << "  " << Member::count() << " members are at test 1" << endl; // 6
	test2();
}



int main() { 
    cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 0 0
    cout << "  " << beni.numFollowers() << " " <<  beni.numFollowing() << endl;  // 0 0
    cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl;  // 0 0
    test1();
    avi.follow(beni);
    
    cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 0 1
    cout << "  " << beni.numFollowers() << " " <<  beni.numFollowing() << endl;  // 1 0
    cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl;  // 0 0
    cout << "  " << Member::count() << " members are at main" << endl; // 3
    test2();
    cout << "  " << Member::count() << " members are at main" << endl; // 3
    
    
  
    Member naor;
    cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl;  // 0 1 
    cout << "  " << naor.numFollowers() << " " <<  naor.numFollowing() << endl;  // 0 0
    avi.unfollow(naor);
    naor.follow(avi);
    naor.follow(beni);
    naor.follow(chana);
    naor.follow(naor);
    
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl;  // 1 1
    cout << "  " << naor.numFollowers() << " " <<  naor.numFollowing() << endl;  // 0 3
    naor.unfollow(naor);
    cout << "  " << naor.numFollowers() << " " <<  naor.numFollowing() << endl;  // 0 3
}
