


```mermaid
flowchart TD
 Start([Start]) --> Input[/รับคะแนน score/]
 Input --> D1{score >= 80?}
 D1 -->|Yes| A[เกรด = A]
 D1 -->|No| D2{score >= 70?}
 D2 -->|Yes| B[เกรด = B]
 D2 -->|No| D3{score >= 60?}
 D3 -->|Yes| C[เกรด = C]
 D3 -->|No| D4{score >= 50?}
 D4 -->|Yes| D[เกรด = D]
 D4 -->|No| F[เกรด = F]
 A & B & C & D & F --> Output[/แสดงเกรด/]
 Output --> End([End])
```




```mermaid
flowchart TD
 Start([Start]) --> Input[/รับ aเเละb /]
 Input --> A{a>b?}
 A --> |Yes| a[/เเสดง a/]
 A --> |No| b[/เเสดง b/]
 a & b --> End([End])
  
 
```

```mermaid
flowchart TD
 Start([Start]) --> Input[/รับ N /]
 Input --> A[i = 1]
 A --> B{i <= n}
 B --> |Yes| a[/พิมพ์ i/]
 a --> c[i =i+1]
 c --> B
 B --> |No| b([End])


```


<style>#mermaid-1782980130266{font-family:sans-serif;font-size:16px;fill:#333;}@keyframes edge-animation-frame{from{stroke-dashoffset:0;}}@keyframes dash{to{stroke-dashoffset:0;}}#mermaid-1782980130266 .edge-animation-slow{stroke-dasharray:9,5!important;stroke-dashoffset:900;animation:dash 50s linear infinite;stroke-linecap:round;}#mermaid-1782980130266 .edge-animation-fast{stroke-dasharray:9,5!important;stroke-dashoffset:900;animation:dash 20s linear infinite;stroke-linecap:round;}#mermaid-1782980130266 .error-icon{fill:#552222;}#mermaid-1782980130266 .error-text{fill:#552222;stroke:#552222;}#mermaid-1782980130266 .edge-thickness-normal{stroke-width:1px;}#mermaid-1782980130266 .edge-thickness-thick{stroke-width:3.5px;}#mermaid-1782980130266 .edge-pattern-solid{stroke-dasharray:0;}#mermaid-1782980130266 .edge-thickness-invisible{stroke-width:0;fill:none;}#mermaid-1782980130266 .edge-pattern-dashed{stroke-dasharray:3;}#mermaid-1782980130266 .edge-pattern-dotted{stroke-dasharray:2;}#mermaid-1782980130266 .marker{fill:#333333;stroke:#333333;}#mermaid-1782980130266 .marker.cross{stroke:#333333;}#mermaid-1782980130266 svg{font-family:sans-serif;font-size:16px;}#mermaid-1782980130266 p{margin:0;}#mermaid-1782980130266 .node .neo-node{stroke:#9370DB;}#mermaid-1782980130266 [data-look="neo"].node rect,#mermaid-1782980130266 [data-look="neo"].cluster rect,#mermaid-1782980130266 [data-look="neo"].node polygon{stroke:#9370DB;filter:drop-shadow(1px 2px 2px rgba(185, 185, 185, 1));}#mermaid-1782980130266 [data-look="neo"].node path{stroke:#9370DB;stroke-width:1px;}#mermaid-1782980130266 [data-look="neo"].node .outer-path{filter:drop-shadow(1px 2px 2px rgba(185, 185, 185, 1));}#mermaid-1782980130266 [data-look="neo"].node .neo-line path{stroke:#9370DB;filter:none;}#mermaid-1782980130266 [data-look="neo"].node circle{stroke:#9370DB;filter:drop-shadow(1px 2px 2px rgba(185, 185, 185, 1));}#mermaid-1782980130266 [data-look="neo"].node circle .state-start{fill:#000000;}#mermaid-1782980130266 [data-look="neo"].icon-shape .icon{fill:#9370DB;filter:drop-shadow(1px 2px 2px rgba(185, 185, 185, 1));}#mermaid-1782980130266 [data-look="neo"].icon-shape .icon-neo path{stroke:#9370DB;filter:drop-shadow(1px 2px 2px rgba(185, 185, 185, 1));}#mermaid-1782980130266 :root{--mermaid-font-family:sans-serif;}#mermaid-1782980130266 :root{--mermaid-alt-font-family:sans-serif;}</style>
