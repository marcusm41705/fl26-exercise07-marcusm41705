////////////////////////////////////////////////////////
// ECE 3574 Exercise: CMake using Catch - starter code
//
#define CATCH_CONFIG_MAIN  // This line tells Catch to provide a main() function
                           // - do this in one cpp file only
#include "catch.hpp"       // This line provides access to all Catch macros
                           // - do not modify catch.hpp
#include "treap.h"
#include <cassert>    
#include <cstdlib>

TEST_CASE("treap unit test1", "[treap]") {

	struct TreapNode *root = NULL; 
	root = insert(root, 50);
	
	TreapNode *res = search(root, 50);
	REQUIRE(res->key == 50);

}
TEST_CASE("Inserting Node", "[treap]"){
	TreapNode *t = NULL;
	t = insert(t, 75);
	TreapNode *t_r = search(t, 75);
	REQUIRE(t_r != NULL);
	REQUIRE(t_r->key == 75);
}
TEST_CASE("Searching for Node/Missing", "[treap]"){
	TreapNode *t = NULL;
	t = insert(t, 40);
	t = insert(t, 80);
	t = insert(t, 90);
	TreapNode *t_s = search(t,100);
	REQUIRE(t_s == NULL);
}
TEST_CASE("Insert Multiple Nodes/Search Testing", "[treap]"){
	TreapNode *t = NULL;
	t = insert(t,30);
	t = insert(t,40);
	t = insert(t,50);
	t = insert(t,60);
	t = insert(t,70);
	REQUIRE(search(t,30) != NULL);
	REQUIRE(search(t,40) != NULL);
	REQUIRE(search(t,50) != NULL);
	REQUIRE(search(t,60) != NULL);
	REQUIRE(search(t,70) != NULL);
	
}
TEST_CASE("Deleting EXISTING Node", "[treap]"){
	TreapNode *t = NULL;
	t = insert(t,10);
	t = insert(t,20);
	t = insert(t,30);
	t = insert(t,40);
	t = deleteNode(t,30);
	REQUIRE(search(t,30) == NULL);
	REQUIRE(search(t,10) != NULL);

}
TEST_CASE("Deleting Non Existent Node Test", "[treap]"){
	TreapNode *t = NULL;
	t = insert(t,10);
	t = insert(t,20);
	t = insert(t,30);
	t = deleteNode(t,50);
	REQUIRE(search(t,10) != NULL);
	REQUIRE(search(t,20) != NULL);
	REQUIRE(search(t,30) != NULL);

}

