#%%
print("원하시는 계산을 적으세요.")
_cmd = input()

print(f'당신은 {_cmd} 입력하셨습니다.')


# %%
_cmd = _cmd.split()

if _cmd[1] == '+' :
    print(int(_cmd[0]) + int(_cmd[2]) )
elif _cmd[1] == '-':
    print(int(_cmd[0]) - int(_cmd[2]) )





# %%
