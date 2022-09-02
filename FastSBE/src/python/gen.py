class MessageGen:
    def __init__(self, name, id, description):
        self.name = name
        self.id = id
        self.description = description

    def generate_tabs(self, tab_index):
        str = " " * 4 * tab_index;
        return str;

    def generate_header(self, tab_index, include_list = []):
        print("Hello my name is " + self.name)

    def generate_message(self)
        