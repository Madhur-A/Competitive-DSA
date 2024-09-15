%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).


-spec reverse_list(Head :: #list_node{} | null) -> #list_node{} | null.

rx(null, Last) -> Last;
rx(#list_node{val = Value, next = Next}, Last) -> rx(Next, #list_node{val = Value, next = Last}).

reverse_list(Head) -> rx(Head, null).
