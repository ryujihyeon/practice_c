#%%
_a = 'hello hello llo eelo llo  halo llo' 
_b = 'libex04'
_c = 'libex03'
_a.startswith('he')

# %%
_a.endswith('lo')

# %%

_b.startswith('lib')


# %%
_c.find('ex')

# %%
_a.count('llo')


# %%

_lt = "       front line          "
print('before' + _lt)
__lt = str.lstrip(_lt)
print('after' + _lt)
print('after' + __lt)

# %%
_lt = "       front line          "
__lt = _lt.lstrip()
print('after' + _lt)
print('after' + __lt)



# %%
print(str.isalpha('helllo'))

# %%
print(str.isdigit('helllo'))
print(str.isdigit('314'))

# %%
name = "lsj"
age = 50
print(f'my name {name} my age{age}')

# %%

data = "lee seon jun"
_data = data.split()

print(_data[0])
print(_data[1])
print(_data[2])

# %%
data = "kor/eng/math/the society"

data.split('/')

# %%
data = input()
data.split()

# %%
