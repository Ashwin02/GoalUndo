/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"

class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

// Tests whether a valid goal and operation are added.

TEST(GoalUndoTest, addOperationNormalCheck)
{
  GoalUndo obj;
  obj.addOperation("firstGoal","firstOP");
	ASSERT_EQ("firstGoal",obj.getGoal());
}

// I am passing an empty string for an operation name.
// The function should return nothing.

TEST(GoalUndoTest, addOperationBlankOpNameCheck)
{
  GoalUndo obj;
  obj.addOperation("firstGoal","");
	ASSERT_EQ("",obj.getGoal());
}

// I am passing an empty string for goal name.
// The function should return nothing.

TEST(GoalUndoTest, addOperationBlankGoalNameCheck)
{
  GoalUndo obj;
  obj.addOperation("","firstOp");
	ASSERT_EQ("",obj.getGoal());
}

// I am passing an empty string for goal name and operation name.
// The function should return nothing.

TEST(GoalUndoTest, addOperationBothBlankNameCheck)
{
  GoalUndo obj;
  obj.addOperation("","");
	ASSERT_EQ("",obj.getGoal());
}

// Tests whether a valid operation is added.

TEST(GoalUndoTest, addOperation2NormalCheck)
{
  GoalUndo obj;
  obj.addOperation("goal1","op1");
  obj.addOperation("op2");
	ASSERT_EQ("op1 op2",obj.getOperations());
}


TEST(GoalUndoTest, addOperation2BlankOpNameCheck)
{
  GoalUndo obj;
  obj.addOperation("goal1","op1");
  obj.addOperation("");
	ASSERT_EQ("op1",obj.getOperations());
}

TEST(GoalUndoTest, addOperation2BlankNameCheck)
{
  GoalUndo obj;
  //obj.addOperation("goal1","op1");
  obj.addOperation("");
	ASSERT_EQ("",obj.getOperations());
}

TEST(GoalUndoTest, addOperation2BlankGoalNameCheck)
{
  GoalUndo obj;
  //obj.addOperation("goal1","op1");
  obj.addOperation("op1");
	ASSERT_EQ("op1",obj.getGoal());
}
