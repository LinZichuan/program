import theano
import theano.tensor as T
#from theano import pp
x = T.dscalar('x')
y = x ** 2
gy = T.grad(y, x)
f = theano.function([x], gy)
print f(4)

x = T.dmatrix('x')
s = T.sum(1 / (1 + T.exp(-x)))
gs = T.grad(s, x)
dlogis = theano.function([x], gs)
print dlogis([[0, 1], [-1, -2]])

x = T.dvector('x')
y = x ** 2
J, updates = theano.scan(lambda i, y,x : T.grad(y[i], x), sequences=T.arange(y.shape[0]), non_sequences=[y,x])
f = theano.function([x], J, updates=updates)
print f([4, 4])
