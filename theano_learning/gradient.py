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

