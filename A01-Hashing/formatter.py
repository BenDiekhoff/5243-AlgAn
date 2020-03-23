for i in range (0,8):
    # good = []
    # with open(f"file{i} INPUT.txt","r") as f:
    #     content =  f.readlines()
    #     for whatever in content:
    #         whatever = whatever.rstrip()

    #         good.append(whatever)
    #     print(good)

    # with open (f"zzOUTPUT.txt","w+") as w:
    #     for i in range (0,34):
    #         for j in range(0+i,311,34):
    #             w.writelines(f"{good[j]}\t")
    #         w.writelines("\n")


  with open (f"zzOUTPUT.txt","a+") as w:
        with open(f"zfile{i} output.txt","r") as f:
            content = f.read()
            w.write(content)
            w.write("\n\n\n")