program korrot;
var fi,fo:text; n,m,k,p,i,j,d:integer; s:string; c:char;
    o:array[1..209,1..209] of byte;
begin
  assign(fi,'input.txt');reset(fi);
  readln(fi,n,m); readln(fi,k,p);
  for i:=1 to n do for j:=1 to m do o[i,j]:=0;
  while not eof(fi) do
    repeat
      readln(fi,i,j);
      if (i in [1..n])and(j in [1..m]) then o[i,j]:=1;
    until eoln(fi);
  close(fi);
  s:=''; j:=k; i:=1;
  repeat
    d:=p-j;
    if i=n then if d=0 then c:='P'
                else if d>0 then if o[i,j+1]=0 then c:='D'
                                 else c:='B'
                     else if o[i,j-1]=0 then c:='S'
                          else c:='B'
     else if j=m then c:='S'
          else if o[i+1,j]=0 then c:='A'
               else if (d>=0)or(i<n-1) then c:='D'
                    else c:='S';
   case c of
       'D':inc(j);
       'S':dec(j);
       'A':inc(i);
       'B':dec(i);
   end;
   if (c<>'P') then if o[i,j]<>0 then c:='C'
                    else begin s:=s+c; o[i,j]:=1; end;
  until (c='P') or (c='C');
  assign(fo,'output.txt');rewrite(fo);
  writeln(fo,s); writeln(fo,c); flush(fo); close(fo);
end.
Nome: Korrot.pas
Autore: sergio casiraghi
Data: 29/01/05
Descrizione: soluzione del problema della poltrona di Korrot proposto
             alle Regionali IOI 2005
CopyLeft
