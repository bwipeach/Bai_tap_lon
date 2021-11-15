// Làm việc với dslk
struct Node{
    Animal data;
    Node *next;
};
struct SList{
	Node *head;
	Node *tail;
	long size;
	SList();
    ~SList();
	Node* CreateNode(Animal v);
    void addLast(Animal v);
    Node *previous(Node *p);
    Node *searchName(Node *p, string name);
    void sort();
    void removeName(Node *p, string name);
    void traverse() const;
};
Node* SList::CreateNode(Animal v){
	Node* p = new Node;
	p->data = v;	
	p->next = NULL;	
	return p; 
}
// thêm vào cuối
void SList::addLast(Animal v){
    Node *p = CreateNode(v);
    if(size == 0){
        head = p;
        tail = p;
    }
    else{
        tail->next = p;
        tail = p;
    }
    size = size + 1;
}