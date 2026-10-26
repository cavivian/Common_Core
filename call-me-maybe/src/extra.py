# print("end_of_sentence:", modello._tokenizer.eos_token_id)
# print(encoding)
# encoding_answer = []
# answer = ""
# for _ in results:  # qua anziche' range, va passata la lista di prompt,
# la mia results
# formatted = modello(richiesta)
# encoding = modello.encode(formatted)[0].tolist()
# logits = modello.get_logits_from_input_ids(encoding)
# next_token = np.argmax(logits)
# next_word = modello.decode([next_token])
# print(next_word, end="", flush=True)
# io qua non devo printare niente,
# il risultato deve essere dentro un file json
# if next_token == modello._tokenizer.eos_token_id:
#     break
# encoding.append(next_token)
# encoding_answer.append(next_token)
# answer += next_word
# print()
