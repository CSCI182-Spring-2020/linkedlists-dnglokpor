#pragma once

/// <summary>
/// Class of nodes that can store integer values.
/// </summary>
class Node
{
public:
	enum Priority {LOW, MEDIUM, HIGH, LUDICROUS};
	int _data;
	Priority _priority = LOW;
	Node* _next;
};

