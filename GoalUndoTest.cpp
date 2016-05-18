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
  obj.addOperation("op1");
	ASSERT_EQ("op1",obj.getGoal());
}


TEST(GoalUndoTest, undoOpertaionCheck)
{
  GoalUndo obj;
  obj.addOperation("goal1","op1");
  obj.undoOperation();
	ASSERT_EQ("",obj.getOperations());
}

TEST(GoalUndoTest, undoOpertaionNoGoalCheck)
{
  GoalUndo obj;
  obj.undoOperation();
	ASSERT_EQ("",obj.getOperations());
}

TEST(GoalUndoTest, undoOpertaionNoOpCheck)
{
  GoalUndo obj;
  obj.addOperation("op1");
  obj.undoOperation();
	ASSERT_EQ("",obj.getOperations());
	ASSERT_EQ("",obj.getGoal());
}



TEST(GoalUndoTest, getGoalCheck)
{
  GoalUndo obj;
  obj.addOperation("goal1","op1");
	obj.addOperation("goal2","op2");
	ASSERT_EQ("goal2",obj.getGoal());
}

TEST(GoalUndoTest, getGoalNoGoalCheck)
{
  GoalUndo obj;
	ASSERT_EQ("",obj.getGoal());
}

TEST(GoalUndoTest, getOperationsCheck)
{
  GoalUndo obj;
	ASSERT_EQ("",obj.getOperations());
}

TEST(GoalUndoTest, getOperationsWithOneOpCheck)
{
  GoalUndo obj;
	obj.addOperation("goal1","op1");
	ASSERT_EQ("op1",obj.getOperations());
}

TEST(GoalUndoTest, getOperationsWithOpsCheck)
{
  GoalUndo obj;
	obj.addOperation("goal1","op1");
	obj.addOperation("op2");
	obj.addOperation("op3");
	ASSERT_EQ("op1 op2 op3",obj.getOperations());
}

TEST(GoalUndoTest, normalUndoOpertaion2Check)
{
  GoalUndo obj;
  obj.addOperation("goal1","op1");
  obj.undoOperation("op1");
	ASSERT_EQ("",obj.getOperations());

}

TEST(GoalUndoTest, undoOpertaion2OnlyGoalCheck)
{
  GoalUndo obj;
  obj.addOperation("goal1","op1");
  obj.undoOperation("op1");
	ASSERT_EQ("",obj.getGoal());
}

TEST(GoalUndoTest, undoOpertaion2NoGoalCheck)
{
  GoalUndo obj;
	ASSERT_EQ("",obj.getGoal());
}

TEST(GoalUndoTest, undoOpertaion2OpsCheck)
{
  GoalUndo obj;
  obj.addOperation("goal1","op1");
  obj.addOperation("op2");
	obj.undoOperation("op1");
	ASSERT_EQ("op2",obj.getOperations());
}

TEST(GoalUndoTest, undoGoalCheck)
{
  GoalUndo obj;
	obj.addOperation("goal1","op1");
	obj.undoGoal();
	ASSERT_EQ("",obj.getGoal());
}

TEST(GoalUndoTest, undoGoalOpsCheck)
{
  GoalUndo obj;
	obj.addOperation("goal1","op1");
	obj.undoGoal();
	ASSERT_EQ("",obj.getOperations());
}
TEST(GoalUndoTest, undoGoalNoGoalCheck)
{
  GoalUndo obj;
	obj.undoGoal();
	ASSERT_EQ("",obj.getOperations());
}
