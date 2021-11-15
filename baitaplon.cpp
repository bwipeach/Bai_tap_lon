class Animal{
    private:   
        string name;
        float height,weight;
        int ID;
    public:
    	virtual void toStream (istream& is);
        friend istream& operator >> (istream& ,Animal* );
        friend ostream& operator << (ostream& os,Animal* al);
        Animal operator = (Animal* al); 
        
        Animal();
        Animal(string name,float height, float weight, int ID);
        Animal(Animal* al);
        ~Animal();
        
        
        string getName(){
        	return name; 
		} 
        int getID(){
            return ID;
        }
               
};
// Làm việc với dslk
struct Node{
    Animal *data;
    Node *next;
};
struct SList{
	Node *head;
	Node *tail;
	long size;
	SList();
    ~SList();
	Node* CreateNode(Animal *v);
    void addLast(Animal *v);
    void insertAfter(Node *p, Animal *v);
    Node *previous(Node *p);
    Node *searchName(Node *p, string name);
    void sort();
    void removeName(Node *p, string name);
    void traverse() const;
};
Node* SList::CreateNode(Animal *v){
	Node* p = new Node;
    Animal *v1 = new Animal(v);
	p->data = v1;	
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
void SList::insertAfter(Node *p, Animal *v) {
	if (p == tail)
		addLast(v);
	else {
		Node *q = CreateNode(v);
		q->next = p->next;
		p->next = q;	  
	}
	size++;
}
// Duyet cac ptu trong danh sach
void SList::traverse() const{
    Node *p = head;
    while(p != NULL){
        cout << p->data <<"\t"; 
        p = p->next;
    }
    cout <<endl;
    delete p;
}
// Tìm kiếm 
Node *SList::searchName(Node *p, string name){
    cout <<"Enter the name: ";
    getline(cin,name);
    if(p == NULL){
        return NULL;
    }
    while(p != NULL){
        if(p->data->getName() == name)
            break;
        p=p->next;
    }
    return p;
}