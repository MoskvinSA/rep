#include "polynomial.h"
#include "TList.h"
#include "monom.h"
#include <gtest.h>

 TEST(List, can_add_front) {
     List<int> l;
     ASSERT_NO_THROW(l.push_front(1));
 }

 TEST(List, get_front_value)
 {
     List<int> l;
     l.push_front(1);
     EXPECT_EQ(1, l.front()->value);
 }

 TEST(List, empty_list)
 {
     List<int> l;
     EXPECT_EQ(true, l.empty());
 }

 TEST(List, can_delete_front) {
     List<int> l;
     l.push_front(1);
     ASSERT_NO_THROW(l.pop_front());
 }

 TEST(List, can_add_back) {
     List<int> l;
     l.push_back(1);
     EXPECT_EQ(1, l.front()->value);
 }

 TEST(List, can_delete_back) {
     List<int> l;
     l.push_front(1);
     l.push_front(2);
     ASSERT_NO_THROW(l.pop_back());
 }

 TEST(List, no_throw_copied_list)
 {
     List<int> l1;
     l1.push_back(1);
     l1.push_back(2);
     ASSERT_NO_THROW(List<int> l2(l1));
 }

 TEST(List, can_equally_list)
 {
     List<int> l1, l2;
     l1.push_back(1);
     l1.push_back(2);
     ASSERT_NO_THROW(l2 = l1);
 }

 TEST(List, can_assign_list) {
     List<int> l1, l2;
     l1.push_back(1);
     l1.push_back(2);
     l2 = l1;
     EXPECT_TRUE(l1 == l2);
 }

 TEST(List, can_create_copied_list) {
     List<int> l1;
     l1.push_back(1);
     l1.push_back(2);
     List<int> l2(l1);
     EXPECT_TRUE(l1 == l2);
 }

 TEST(Monom, can_create_monom) {
     ASSERT_NO_THROW(Monom m1);
 }

 TEST(Monom, no_throw_copied_monom) {
     Monom m1(2, 3);
     ASSERT_NO_THROW(Monom m2(m1));
 }

 TEST(Monom, can_get_coef) {
     Monom m(2, 3);
     EXPECT_EQ(2, m.get_coef());
 }

 TEST(Monom, can_set_coef) {
     Monom m;
     m.get_coef() = 2;
     EXPECT_EQ(2, m.get_coef());
 }

 TEST(Monom, can_get_exp) {
     Monom m(2, 3);
     EXPECT_EQ(3, m.get_ex());
 }

 TEST(Monom, can_create_copied_monom) {
     Monom m1(2, 3);
     Monom m2(m1);
     EXPECT_TRUE(m1 == m2);
 }

 TEST(Monom, can_assign_monom) {
     Monom m1(2, 3), m2;
     m2 = m1;
     EXPECT_TRUE(m1 == m2);
 }

 TEST(Monom, cant_add_monom_with_different_exp) {
     Monom m1(2, 3), m2(4, 5);
     ASSERT_ANY_THROW(m1 + m2);
 }

 TEST(Monom, can_add_monom_with_equal_exp) {
     Monom m1(2, 3), m2(4, 3), m3;
     m3 = m1 + m2;
     EXPECT_EQ(6, m3.get_coef());
 }

 TEST(Monom, cant_sub_monom_with_different_exp) {
     Monom m1(2, 3), m2(4, 5);
     ASSERT_ANY_THROW(m1 - m2);
 }

 TEST(Monom, can_add_sub_with_equal_exp) {
     Monom m1(4, 3), m2(2, 3), m3;
     m3 = m1 - m2;
     EXPECT_EQ(2, m3.get_coef());
 }

 TEST(Monom, can_mult_monom) {
     Monom m1(4, 3), m2(2, 3), m3(8, 6);
     EXPECT_TRUE(m1*m2 == m3);
 }

 TEST(Polynom, no_throw_create_polynom) {
     ASSERT_NO_THROW(Polynom p("3.5x2y3-6.7y6z8"));
 }

 TEST(Polynom, can_create_polynom) {
     Polynom p("3.5x2y3-6.7y6z8");
     List<Monom> ls = p.get_list();
     Link<Monom>* pm = ls.front();
     Monom m1(3.5, 860), m2(-6.7, 128);
     EXPECT_TRUE(m1 == pm->value);
     pm = pm->next;
     EXPECT_TRUE(m2 == pm->value);
 }

 TEST(Polynom, can_create_copied_polynom) {
     Polynom p1("3.5x2y3-6.7y6z8");
     Polynom p2(p1);
     EXPECT_TRUE(p1 == p2);
 }

 TEST(Polynom, can_add_monom) {
     Polynom p;
     Monom m(2, 3);
     ASSERT_NO_THROW(p.add_monom(m));
     List<Monom> ls = p.get_list();
     EXPECT_TRUE(m == ls.front()->value);
 }

 TEST(Polynom, can_assign_polynom) {
     Polynom p1("3.5x2y3-6.7y6z8"), p2;
     p2 = p1;
     EXPECT_TRUE(p1 == p2);
 }

 TEST(Polynom, can_add_polynom) {
     Polynom p1("2x2y3-3y2z3"), p2("4y2z3+2x"), p3("2x2y3+y2z3+2x"), p4;
     p4 = p1 + p2;
     EXPECT_TRUE(p3 == p4);

 }

 TEST(Polynom, can_sub_polynom) {
     Polynom p1("2x2y3-3y2z3"), p2("4y2z3+2x"), p3("2x2y3-7y2z3-2x"), p4;
     p4 = p1 - p2;
     //cout << p4;
     EXPECT_TRUE(p3 == p4);
 }

 TEST(Polynom, can_mult_polynom) {
     Polynom p1("2x2y3-3y2z3"), p2("4y2z3+2x"), p3("8x2y5z3+4x3y3-12y4z6-6xy2z3"), p4;
     p4 = p1 * p2;
     EXPECT_TRUE(p3 == p4);
 }

 TEST(Polynom, can_get_result) {
     Polynom p1("3x2y3+6y6z8");
     double a = p1.calculate_result(3, 2, 1);
     EXPECT_DOUBLE_EQ(600.0, a);
 }