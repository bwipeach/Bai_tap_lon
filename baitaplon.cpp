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
struct NodeL{
    Animal *data;
    NodeL *next;
};
struct SList{
	NodeL *head;
	NodeL *tail;
	long size;
	SList();
    ~SList();
	NodeL* CreateNodeL(Animal *v);
    void addLast(Animal *v);
    NodeL *previous(NodeL *p);
    NodeL *searchName(NodeL *p, string name);
    void sort();
    void removeFirst();
    void removeLast();
    void removeName();
    void traverse() const;
};
NodeL* SList::CreateNodeL(Animal *v){
	NodeL* p = new NodeL;
    Animal *v1 = new Animal(v);
	p->data = v1;	
	p->next = NULL;	
	return p; 
}
// thêm vào cuối
void SList::addLast(Animal v){
    NodeL *p = CreateNodeL(v);
    if(size == 0){
        head = p;
        tail = p;
    }
    else{
        tail->next = p;
        tail = p;
    }
    size = size + 1;

// Duyet cac ptu trong danh sach
void SList::traverse() const{
    NodeL *p = head;
    while(p != NULL){
        cout << p->data <<"\t"; 
        p = p->next;
    }
    cout <<endl;
    delete p;
}
// Tìm kiếm 
NodeL *SList::searchName(NodeL *p, string name){
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
// Sắp xếp
void SList::sort(){
    for(NodeL *p = head; p != tail; p=p->next){
        for(NodeL *q = p->next; q != NULL; q = q->next){
            if(p->data->getID() > q->data->getID()){
                swap(p->data,q->data);
            }
        }
    }
}
// tìm 1 phần tử ngay trước phần tử bất kì
NodeL* SList::previous(NodeL *p) {
	NodeL *t = head;
	while (t->next != p)
		t = t->next;
	return t;
}
// xoa o vi tri dau
void SList::removeFirst(){
   if(size == 0){
   	    return;
	}else{
		NodeL*t = head;
		head=head->next;
		delete t;
		size--;
    }
}
// xoa o vi tri cuoi
void SList::removeLast(){
	NodeL *pre = previous(tail);
	NodeL*t =tail;
	pre->next=NULL;
	tail=pre;
	delete t;
	size--;
}	


// xoa 1 ptu o vi tri bat ki
void SList::removeName(){
    string name;
    cout<<"Nhap ten dong vat can xoa:";
    fflush(stdin);
    getline(cin,name);
    NodeL*p=head;
    for(p;p!=NULL;p=p->next){
        if(p->data->getName()==name){
            if(p == head){
                removeFirst();
                break;
            }
            else if(p==tail){
                removeLast();
                break;
            }
            else{
                NodeLL *pre = previous(p);
                pre->next = p->next;
                delete p;
                size--;
                break;
            }
        }
    }
    if(p == NULL){
            cout <<"Khong tim thay ten dong vat can xoa"<<endl;
        }
}