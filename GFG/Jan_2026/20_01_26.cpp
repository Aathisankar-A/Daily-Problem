class Solution {
  public:
    string doc;
    stack<char> undone;

    void append(char x) {
        // append x into document
        doc.push_back(x);
        while(!undone.empty()) undone.pop();
    }

    void undo() {
        // undo last change
        if(doc.empty()) return;
        undone.push(doc.back());
        doc.pop_back();
    }

    void redo() {
        // redo changes
        if(undone.empty()) return;
        doc.push_back(undone.top());
        undone.pop();
    }

    string read() {
        // read the document
        return doc;
    }
};
