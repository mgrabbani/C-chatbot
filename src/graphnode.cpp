#include "graphedge.h"
#include "graphnode.h"
#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge* edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
// void GraphNode::MoveChatbotHere(ChatBot* chatbot)
// {
//     _chatBot = chatbot;
//     std::cout << "Inside MoveChatbotHere: middle\n";
//     _chatBot->SetCurrentNode(this);
//     std::cout << "Inside MoveChatbotHere: end\n";
// }
// void GraphNode::MoveChatbotHere(std::unique_ptr<ChatBot> chatbot)
// {
//     _chatBot = std::move(chatbot);
//     std::cout << "Inside MoveChatbotHere: middle\n";
//     _chatBot->SetCurrentNode(this);
//     std::cout << "Inside MoveChatbotHere: end\n";
// }
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    // std::cout << "Inside MoveChatbotHere: start\n";
    _chatBot = std::move(chatbot);
    // std::cout << "Inside MoveChatbotHere: middle\n";
    _chatBot.SetCurrentNode(this);
    // std::cout << "Inside MoveChatbotHere: end\n";
}

// void GraphNode::MoveChatbotToNewNode(GraphNode* newNode)
// {
//     newNode->MoveChatbotHere(_chatBot);
//     _chatBot = nullptr; // invalidate pointer at source
// }
// void GraphNode::MoveChatbotToNewNode(GraphNode* newNode)
// {
//     newNode->MoveChatbotHere(std::move(_chatBot));
//     //_chatBot = nullptr; // invalidate pointer at source
// }
void GraphNode::MoveChatbotToNewNode(GraphNode* newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge* GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}