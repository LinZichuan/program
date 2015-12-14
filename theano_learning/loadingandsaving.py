import cPickle

f = file('obj.save', 'wb')

class my_obj:
    def __init__(self):
        pass


cPickle.dump(my_obj, f, protocol=cPickle.HIGHEST_PROTOCOL)
f.close()
