template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* newNode = new Node(elem);  
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    this->length = 0;  
}
template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    // TODO
    if (copyObj.head == nullptr){
        return;
        head = new Node(copyObj.head->value);
        Node* curr = head;
        Node* copyObjCurr = copyObj.head->next;
        while(copyObjCurr != nullptr){
            curr->next = new Node(copyObjCurr->value);
            curr = curr->next;
            copyObjCurr = copyObjCurr->next;
        }
       this->length = copyObj.length;
    }
   
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("Position is out of range.");  
    }
    Node* curr = head;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    return curr->value;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > this->length) {  
        throw string("Position is out of range.");   
    }
    Node* newNode = new Node(elem);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* curr = head;
        for (int i = 0; i < position - 1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    this->length++;  // FIXED: added this->
}

template <typename T>
void LinkedList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        throw string("Position is out of range.");  // FIXED: throw string
    }
    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else {
        Node* curr = head;
        for (int i = 0; i < position - 1; i++) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    this->length--;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("Position is out of range.");  // FIXED: throw string
    }
    Node* curr = head;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }
    return outStream;
}

