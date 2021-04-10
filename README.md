# Linux_Design_Lab0
lab0-c
queue.c 僅提供介面 (interface) 但尚未有完整程式實作，需要由學員補完並逐步精進，包含以下:

    q_new: 建立新的「空」佇列;
    q_free: 釋放佇列所佔用的記憶體;
    q_insert_head: 在佇列開頭 (head) 加入 (insert) 給定的新元素 (以 LIFO 準則);
    q_insert_tail: 在佇列尾端 (tail) 加入 (insert) 給定的新元素 (以 FIFO 準則);
    q_remove_head: 在佇列開頭 (head) 移去 (remove) 給定的元素。
    q_size: 計算佇列中的元素數量。
    q_reverse: 以反向順序重新排列鏈結串列，該函式不該配置或釋放任何鏈結串列元素，換言之，它只能重排已經存在的元素;
    q_sort: 「Linux 核心設計」課程所新增，以遞增順序來排序鏈結串列的元素，可參閱 Linked List Sort 得知實作手法
  
