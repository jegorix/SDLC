# InvestLab — functional priorities (10 highest → 50 lowest)

**Дата:** 2026-10-31. **Оценки:** учебные человеко-дни (весь объём), не фактически оставшееся время после прототипа.

| Feature | Description | Requirement IDs | Priority | Est. days | Release |
|---|---|---|---:|---:|---|
| F01 | Qt6 desktop shell & navigation | REQ-INT-002 | 10 | 5 | MVP |
| F02 | Historical market data + validation | REQ-INT-001, REQ-FUNC-017/018 | 10 | 8 | MVP |
| F03 | Portfolio setup & allocation | REQ-FUNC-001–005, 011 | 10 | 8 | MVP |
| F04 | Buy & Hold + fee calculation | REQ-FUNC-006, 010 | 10 | 5 | MVP |
| F05 | DCA recurring contributions | REQ-FUNC-007 | 20 | 7 | MVP |
| F06 | SQLite persistence & history | REQ-FUNC-012/013, REQ-REL-001 | 20 | 7 | MVP |
| F07 | Summary metrics & equity chart | REQ-FUNC-014/015 | 20 | 6 | MVP |
| F08 | SMA strategy | REQ-FUNC-008 | 30 | 7 | MVP |
| F09 | RSI strategy | REQ-FUNC-009 | 50 | 7 | Future |
| F10 | Extended summary, QA & release | REQ-FUNC-016, REQ-SEC-001, REQ-PORT-001 | 10 | 8 | MVP |
| F11 | Compare two simulations | REQ-FUNC-019 (new) | 20 | 12 | MVP |

**Шкала:** 10 — критично; 20 — важно; 30 — желательно; 40 — опционально; 50 — минимальный приоритет, возможно отложить.

**CR-001:** RSI / F09 перенесён в будущую версию, оценка 7 дней сохраняется, приоритет изменён с 30 на 50.

**CR-002:** запрос сравнения двух сохранённых симуляций / F11 / REQ-FUNC-019, приоритет 20 и 12 дней разработки.
