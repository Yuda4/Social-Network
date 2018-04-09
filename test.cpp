#include <iostream>
using namespace std;

#include "Member.h"


Member avi, beni, chana;

void test2() {
	Member dana, shlomi;
	cout << "  " << dana.get_ID() << " dana's id test 2" << endl; 
	shlomi.follow(dana);
	shlomi.follow(avi);
	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; 
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl;
        cout << "  " << shlomi.numFollowers() << " " <<  shlomi.numFollowing() << endl;
	cout << "  " << Member::count() << " members are at test 2" << endl; 
}

void test1() {
    
	Member dana, adiel, yuda;
	chana.follow(dana);
	avi.follow(adiel);
	dana.follow(avi);
	cout << "  " << dana.get_ID() << " dana's id test 1" << endl; 
	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; 
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; 
	cout << "  " << adiel.numFollowers() << " " <<  adiel.numFollowing() << endl; 
	cout << "  " << Member::count() << " members are at test 1" << endl;
	test2();
}


/*
int main() { 
    cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl;
    cout << "  " << beni.numFollowers() << " " <<  beni.numFollowing() << endl;
    cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl;
    test1();
    avi.follow(beni);
    cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl;
    cout << "  " << beni.numFollowers() << " " <<  beni.numFollowing() << endl;
    avi.follow(beni);
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl;
    cout << "  " << beni.numFollowers() << " " <<  beni.numFollowing() << endl;
    cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl;
    cout << "  " << beni.numFollowers() << " " <<  beni.numFollowing() << endl;
    cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl;
    cout << "  " << Member::count() << " members are at main" << endl; 
    test2();
    cout << "  " << Member::count() << " members are at main" << endl; 
    
}*/
